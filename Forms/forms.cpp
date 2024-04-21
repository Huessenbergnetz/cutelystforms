/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
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
#    include <Cutelyst/Plugins/CSRFProtection/CSRFProtection>
#endif

#if defined(QT_DEBUG)
Q_LOGGING_CATEGORY(C_FORMS, "cutelyst.plugin.forms")
#else
Q_LOGGING_CATEGORY(C_FORMS, "cutelyst.plugin.forms", QtWarningMsg)
#endif

using namespace CutelystForms;

static thread_local Forms *forms =
    nullptr; // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

FormsContextObject::FormsContextObject(const QString &form, Cutelyst::Context *c)
    : QObject(c)
    , m_form(form)
    , m_c(c)
{
}

QString
    FormsContextObject::cTr(const QString &sourceText, const QString &disambiguation, int n) const
{
    return m_c->translate(m_form.toUtf8().constData(),
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

QString FormsContextObject::cCsrfToken()
{
#ifdef PLUGIN_CSRFPROTECTION_ENABLED
    return QString::fromLatin1(Cutelyst::CSRFProtection::getToken(m_c));
#else
    qCWarning(C_FORMS, "%s", "The CSRF protection plugin has not been built.");
    return QString();
#endif
}

Forms::Forms(Cutelyst::Application *parent)
    : Plugin(parent)
    , d_ptr(new FormsPrivate)
{
    Q_D(Forms);
    d->engine.setOutputWarningsToStandardError(false);
    connect(&d->engine, &QQmlEngine::warnings, &d->engine, [](const QList<QQmlError> &warnings) {
        for (const QQmlError &warning : warnings) {
            qCWarning(C_FORMS) << warning.toString();
        }
    });
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

Form *Forms::getForm(const QString &name, Cutelyst::Context *c)
{
    if (!forms) {
        qCCritical(C_FORMS) << "Forms plugin not registered";
        return nullptr;
    }

    QFileInfo fi;
    const QStringList includePaths = forms->includePaths();
    for (const QString &path : includePaths) {
        const QString fn = path + QLatin1Char('/') + name + QLatin1String(".qml");
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
    qmlContext.setContextObject(new FormsContextObject(
        fi.completeBaseName(), c)); // NOLINT(cppcoreguidelines-owning-memory)
    auto it = c->stash().cbegin();
    while (it != c->stash().cend()) {
        qmlContext.setContextProperty(it.key(), it.value());
        it++;
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
    connect(app, &Cutelyst::Application::postForked, this, [](Cutelyst::Application *app) {
        forms = app->plugin<Forms *>();
    });

    return true;
}

#include "moc_forms.cpp"
