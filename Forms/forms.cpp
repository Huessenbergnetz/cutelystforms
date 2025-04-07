/*!
 * SPDX-FileCopyrightText: (C) 2023-2025 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "forms_p.h"
#include "logging_p.h"

#include <Cutelyst/Application>
#include <Cutelyst/Context>

#include <QFileInfo>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlError>
#include <QStringList>

#ifdef PLUGIN_CSRFPROTECTION_ENABLED
#    include <Cutelyst/Plugins/CSRFProtection>
#endif

#if defined(QT_DEBUG)
Q_LOGGING_CATEGORY(C_FORMS, "cutelyst.plugin.forms")
#else
Q_LOGGING_CATEGORY(C_FORMS, "cutelyst.plugin.forms", QtWarningMsg)
#endif

using namespace CutelystForms;

// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
static thread_local Forms *forms = nullptr;

FormsContextObject::FormsContextObject(QStringView form, Cutelyst::Context *c)
    : QObject(c)
    , m_form(form.toUtf8())
    , m_c(c)
{
}

QString
    FormsContextObject::cTr(const QString &sourceText, const QString &disambiguation, int n) const
{
    return m_c->translate(m_form.constData(),
                          sourceText.toUtf8().constData(),
                          disambiguation.toUtf8().constData(),
                          n);
}

QString FormsContextObject::cTrId(const QString &id, int n) const
{
    return m_c->translate(nullptr, id.toUtf8().constData(), nullptr, n);
}

QString FormsContextObject::cTranslate(const QString &context,
                                       const QString &sourceText,
                                       const QString &disambiguation,
                                       int n) const
{
    return m_c->translate(context.toUtf8().constData(),
                          sourceText.toUtf8().constData(),
                          disambiguation.toUtf8().constData(),
                          n);
}

QUrl FormsContextObject::cUriFor(const QString &path,
                                 const QStringList &args,
                                 const QVariantMap &queryValues) const
{
    if (queryValues.empty()) {
        return m_c->uriFor(path, args);
    } else {
        Cutelyst::ParamsMultiMap map;
        auto it = queryValues.cbegin();
        while (it != queryValues.cend()) {
            map.insert(it.key(), it.value().toString());
            it++;
        }
        return m_c->uriFor(path, args, map);
    }
}

QString FormsContextObject::cCsrfToken() const
{
#ifdef PLUGIN_CSRFPROTECTION_ENABLED
    return QString::fromLatin1(Cutelyst::CSRFProtection::getToken(m_c));
#else
    qCWarning(C_FORMS, "%s", "The CSRF protection plugin has not been built.");
    return {};
#endif
}

QString FormsContextObject::cCsrfTokenFieldName() const
{
#ifdef PLUGIN_CSRFPROTECTION_ENABLED
    return QString::fromLatin1(Cutelyst::CSRFProtection::formFieldName());
#else
    qCWarning(C_FORMS, "%s", "The CSRF protection plugin has not been built.");
    return {};
#endif
}

QVariant FormsContextObject::cStashValue(const QString &key, const QVariant &defVal)
{
    return m_c->stash(key, defVal);
}

Forms::Forms(Cutelyst::Application *parent)
    : Plugin(parent)
    , d_ptr(new FormsPrivate)
{
    Q_D(Forms);
    d->engine.setOutputWarningsToStandardError(false);
    // NOLINTNEXTLINE(bugprone-unused-return-value)
    connect(&d->engine, &QQmlEngine::warnings, &d->engine, [](const QList<QQmlError> &warnings) {
        for (const QQmlError &warning : warnings) {
            qCWarning(C_FORMS) << warning.toString();
        }
    });
}

FormsLoader::FormsLoader(Forms *forms, QObject *parent)
    : QObject{parent}
    , m_forms{forms}
{
}

void FormsLoader::loadForm(const QString &name, Cutelyst::Context *c, Forms::Options options)
{
#if (QT_VERSION < QT_VERSION_CHECK(6, 5, 0))
    QMetaObject::invokeMethod(this,
                              "load",
                              Qt::DirectConnection,
                              Q_ARG(QString, name),
                              Q_ARG(Cutelyst::Context *, c),
                              Q_ARG(CutelystForms::Forms::Options, options));
#else
    QMetaObject::invokeMethod(this, "load", Qt::DirectConnection, name, c, options);
#endif
}

void FormsLoader::load(const QString &name,
                       Cutelyst::Context *c,
                       CutelystForms::Forms::Options options)
{
    Q_ASSERT_X(c, "FormsLoader:load", "we nee a valid Cutelyst context");

    if (!m_forms) {
        qCCritical(C_FORMS) << "Forms plugin not registered";
        Q_EMIT loaded(nullptr);
        return;
    }

    QFileInfo fi;
    const QStringList includePaths = m_forms->includePaths();
    for (const QString &path : includePaths) {
        const QString fn = path + QLatin1Char('/') + name;
        fi.setFile(fn);
        if (fi.exists()) {
            break;
        }
    }

    if (!fi.exists()) {
        qCWarning(C_FORMS) << "Can not find form" << name;
        Q_EMIT loaded(nullptr);
        return;
    }

    QQmlContext qmlContext(&m_forms->d_func()->engine);
    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
    qmlContext.setContextObject(new FormsContextObject(fi.completeBaseName(), c));
    if (!options.testFlag(Forms::DoNotFillContext)) {
        auto it = c->stash().cbegin();
        while (it != c->stash().cend()) {
            qmlContext.setContextProperty(it.key(), it.value());
            it++;
        }
    }

    QQmlComponent component(&m_forms->d_func()->engine, fi.filePath());
    auto formObject = component.create(&qmlContext);
    if (!formObject) {
        qCWarning(C_FORMS) << "Failed to load form" << name
                           << "from QML file:" << component.errorString();
        Q_EMIT loaded(nullptr);
        return;
    }
    auto realFormObject = qobject_cast<Form *>(formObject);
    if (!realFormObject) {
        qCWarning(C_FORMS)
            << "Failed to load form" << name
            << "from QML file. Maybe the root item in the QML file is not of type Form.";
        Q_EMIT loaded(nullptr);
        return;
    }
    realFormObject->setObjectName(name);
    realFormObject->setParent(c);
    realFormObject->setContext(c);
    qCDebug(C_FORMS).noquote() << "Successfully loaded QML form data from" << fi.filePath();
    Q_EMIT loaded(realFormObject);
    return;
}

Forms::~Forms()
{
    delete d_ptr;
}

void Forms::addImportPath(const QString &path)
{
    Q_D(Forms);
    d->engine.addImportPath(path);
}

QStringList Forms::importPaths() const noexcept
{
    Q_D(const Forms);
    return d->engine.importPathList();
}

void Forms::setIncludePaths(const QStringList &paths)
{
    Q_D(Forms);
    d->includePaths = paths;
}

QStringList Forms::includePaths() const noexcept
{
    Q_D(const Forms);
    return d->includePaths;
}

void Forms::setTimezoneStashKey(const QString &key)
{
    Q_D(Forms);
    d->timezoneStashKey = key;
}

QString Forms::timezoneStashKey()
{
    if (!forms) {
        qCCritical(C_FORMS) << "Forms plugin not registered";
        return {};
    }

    return forms->d_func()->timezoneStashKey;
}

Form *Forms::getForm(QStringView name, Cutelyst::Context *c, Options options)
{
    Q_ASSERT_X(c, "Forms::getForm", "we nee a valid Cutelyst context");

    if (!forms) {
        qCCritical(C_FORMS) << "Forms plugin not registered";
        return nullptr;
    }

    QFileInfo fi;
    const QStringList includePaths = forms->includePaths();
    for (const QString &path : includePaths) {
        const QString fn = path + QLatin1Char('/') + name;
        fi.setFile(fn);
        if (fi.exists()) {
            break;
        }
    }

    if (!fi.exists()) {
        qCWarning(C_FORMS) << "Can not find form" << name;
        return nullptr;
    }

    QQmlContext qmlContext(&forms->d_func()->engine);
    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
    qmlContext.setContextObject(new FormsContextObject(fi.completeBaseName(), c));
    if (!options.testFlag(DoNotFillContext)) {
        auto it = c->stash().cbegin();
        while (it != c->stash().cend()) {
            qmlContext.setContextProperty(it.key(), it.value());
            it++;
        }
    }

    QQmlComponent component(&forms->d_func()->engine, fi.filePath());
    auto formObject = component.create(&qmlContext);
    if (!formObject) {
        qCWarning(C_FORMS) << "Failed to load form" << name
                           << "from QML file:" << component.errorString();
        return nullptr;
    }
    auto realFormObject = qobject_cast<Form *>(formObject);
    if (!realFormObject) {
        qCWarning(C_FORMS)
            << "Failed to load form" << name
            << "from QML file. Maybe the root item in the QML file is not of type Form.";
        return nullptr;
    }
    realFormObject->setObjectName(name);
    realFormObject->setParent(c);
    realFormObject->setContext(c);
    qCDebug(C_FORMS).noquote() << "Successfully loaded QML form data from" << fi.filePath();
    return realFormObject;
}

AwaitedForm Forms::coGetForm(const QString &name, Cutelyst::Context *c, Options options)
{
    AwaitedForm coro{c};
    auto cb = coro.callback;

    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
    auto fl = new FormsLoader{forms, c};
    // NOLINTNEXTLINE(bugprone-unused-return-value)
    connect(fl, &FormsLoader::loaded, c, [cb, fl](Form *form) {
        fl->deleteLater();
        cb(form);
    });
    fl->loadForm(name, c, options);
    return coro;
}

QString Forms::templatesDirPath()
{
    return QStringLiteral(CUTELYSTFORMS_TEMPLATESDIR);
}

QString Forms::templateDirPath(QStringView templ)
{
    return QStringLiteral(CUTELYSTFORMS_TEMPLATESDIR) + QLatin1Char('/') + templ;
}

bool Forms::setup(Cutelyst::Application *app)
{
    // NOLINTNEXTLINE(bugprone-unused-return-value)
    connect(app, &Cutelyst::Application::postForked, this, [](Cutelyst::Application *app) {
        forms = app->plugin<Forms *>();
    });

    return true;
}

#include "moc_forms.cpp"
