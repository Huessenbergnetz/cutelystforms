/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FORMSTEST_H
#define FORMSTEST_H

#include "coverageobject.h"

#include <Cutelyst/application.h>
#include <Cutelyst/context.h>
#include <Cutelyst/controller.h>

#include <QLocale>
#include <QObject>
#include <QTest>
#ifdef PLUGIN_CSRFPROTECTION_ENABLED
#    include <Cutelyst/Plugins/CSRFProtection>
#endif
#include <Forms/form.h>
#include <Forms/forms.h>
#include <Forms/hiddeninput.h>
#include <Forms/select.h>

using namespace CutelystForms;

class TestFormsController : public Cutelyst::Controller
{
    Q_OBJECT
public:
    explicit TestFormsController(QObject *parent)
        : Cutelyst::Controller(parent)
    {
    }

    C_ATTR(test0, :Local)
    void test0(Context *c) { Q_UNUSED(c) }
};

class TestForms : public CoverageObject
{
    Q_OBJECT
public:
    explicit TestForms(QObject *parent = nullptr)
        : CoverageObject(parent)
    {
    }

private Q_SLOTS:
    void initTestCase();

    void getForm();

    void cleanupTestCase();

private:
    TestEngine *m_engine{nullptr};

    TestEngine *getEngine();
};

TestEngine *TestForms::getEngine()
{
    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
    auto app = new TestApplication(this);
    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
    auto engine = new TestEngine(app, QVariantMap());
    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
    new TestFormsController(app);

    const QString l10nDir = QStringLiteral(TESTFORMS_L10N_DIR);
    app->loadTranslationsFromDir(QStringLiteral("formtests"), l10nDir);

    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
    auto forms = new Forms(app);
    forms->addImportPath(QStringLiteral(FORMS_IMPORT_DIR));
    forms->setIncludePaths({QStringLiteral(TESTFORMS_DIR)});

#ifdef PLUGIN_CSRFPROTECTION_ENABLED
    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
    auto csrf = new Cutelyst::CSRFProtection(app);
    csrf->setFormFieldName(QByteArrayLiteral("xsrfprotfield"));
#endif

    if (!engine->init()) {
        return nullptr;
    }

    return engine;
}

void TestForms::initTestCase()
{
    m_engine = getEngine();
    QVERIFY(m_engine);
}

void TestForms::cleanupTestCase()
{
    delete m_engine;
    m_engine = nullptr;
}

void TestForms::getForm()
{
    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
    auto c = new Context(m_engine->app());
    c->setLocale(QLocale(QLocale::German));
    c->setStash(QStringLiteral("test"), QStringLiteral("hallo"));
    c->setStash(QStringLiteral("dwarfsCount"), 7);
    auto f = Forms::getForm(QStringLiteral("MyForm.qml"), c);
    QVERIFY(f);
    QCOMPARE(f->htmlId(), QStringLiteral("littleForm"));
    QCOMPARE(f->htmlClass(), QStringLiteral("form"));
    QCOMPARE(f->name(), QStringLiteral("littleForm"));
    QCOMPARE(f->label(), QStringLiteral("7 Zwerge"));
    auto fs0 = f->fieldset(0);
    QVERIFY(fs0);
    QCOMPARE(fs0->htmlId(), QStringLiteral("fieldset1"));
    QCOMPARE(fs0->htmlClass(), QStringLiteral("hallo"));
    auto selectField = qobject_cast<Select *>(fs0->field(0));
    QVERIFY(selectField);
    auto option = selectField->option(0);
    QVERIFY(option);
    QCOMPARE(QString::fromLatin1(option->metaObject()->className()),
             QStringLiteral("CutelystForms::Option"));
    auto fs1 = f->fieldset(1);
    QVERIFY(fs1);
    QCOMPARE(fs1->legend(), QStringLiteral("Eine weitere große Legende"));
    auto csrf = qobject_cast<HiddenInput *>(fs1->field(0));
    QVERIFY(csrf);
    QVERIFY(!csrf->value().isNull());
    QCOMPARE(csrf->name(), QStringLiteral("xsrfprotfield"));
    QCOMPARE(csrf->form(), QStringLiteral("littleForm"));
    auto btn = f->button(0);
    QVERIFY(btn);
    QCOMPARE(btn->form(), QStringLiteral("littleForm"));
}

QTEST_MAIN(TestForms)

#include "testforms.moc"

#endif
