/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORM_H
#define C_FORM_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"
#include "fieldset.h"
#include "button.h"
#include <QObject>
#include <QQmlListProperty>
#include <QUrl>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

namespace CutelystForms {

class FormPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Form : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(QUrl action READ action WRITE setAction)
    Q_PROPERTY(QStringList acceptCharset READ acceptCharset WRITE setAcceptCharset)
    Q_PROPERTY(bool autocomplete READ autocomplete WRITE setAutocomplete)
    Q_PROPERTY(CutelystForms::Form::EncType enctype READ enctype WRITE setEnctype)
    Q_PROPERTY(CutelystForms::Form::Method method READ method WRITE setMethod)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(bool novalidate READ novalidate WRITE setNovalidate)
    Q_PROPERTY(CutelystForms::Form::Target target READ target WRITE setTarget)
    Q_PROPERTY(QString label READ label WRITE setLabel)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(QQmlListProperty<CutelystForms::Fieldset> fieldsets READ fieldsets)
    Q_PROPERTY(QQmlListProperty<CutelystForms::Button> buttons READ buttons)
    Q_PROPERTY(CutelystForms::Form::Type type READ type WRITE setType)
    Q_CLASSINFO("DefaultProperty", "fieldsets")
    QML_ELEMENT
public:
    explicit Form(QObject *parent = nullptr);
    virtual ~Form() override;

    enum EncType {
        WwwFormUrlEncoded   = 0,
        MultipartFormData,
        TextPlain
    };
    Q_ENUM(EncType)

    enum Method {
        Post    = 0,
        Get
    };
    Q_ENUM(Method)

    enum Target {
        Self    = 0,
        Blank,
        Parent,
        Top
    };
    Q_ENUM(Target)

    enum Type : quint8 {
        Vertical    = 0,
        Horizontal  = 1,
        Inline      = 2
    };
    Q_ENUM(Type)

    QUrl action() const;
    void setAction(const QUrl &action);

    QStringList acceptCharset() const;
    void setAcceptCharset(const QStringList &acceptCharset);

    bool autocomplete() const;
    void setAutocomplete(bool autocomplete);

    EncType enctype() const;
    void setEnctype(EncType enctype);

    Method method() const;
    void setMethod(Method method);

    QString name() const;
    void setName(const QString &name);

    bool novalidate() const;
    void setNovalidate(bool novalidate);

    Target target() const;
    void setTarget(Target target);

    QString label() const;
    void setLabel(const QString &label);

    QString description() const;
    void setDescription(const QString &description);

    Type type() const;
    void setType(Type type);

    QQmlListProperty<CutelystForms::Fieldset> fieldsets();
    void appendFieldset(Fieldset *fieldset);
    QList<Fieldset*>::size_type fieldsetCount() const;
    Fieldset *fieldset(QList<Fieldset*>::size_type idx) const;
    void clearFieldsets();
    QList<Fieldset*> fieldsetList() const;

    QQmlListProperty<CutelystForms::Button> buttons();
    void appendButton(Button *button);
    QList<Button*>::size_type buttonCount() const;
    Button *button(QList<Button*>::size_type idx) const;
    void clearButtons();
    QList<Button*> buttonList() const;

protected:
    Form(FormPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Form)
    Q_DECLARE_PRIVATE(Form)
};

}

#endif // C_FORM_H
