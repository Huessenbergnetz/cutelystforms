/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORM_H
#define C_FORM_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"
#include "fieldset.h"
#include "field.h"
#include "button.h"
#include <QObject>
#include <QQmlListProperty>
#include <QUrl>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class FormPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Form : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(QStringList acceptCharset READ acceptCharset WRITE setAcceptCharset)
    Q_PROPERTY(QUrl action READ action WRITE setAction)
    Q_PROPERTY(bool autocomplete READ autocomplete WRITE setAutocomplete)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(CutelystForms::Form::EncType enctype READ enctype WRITE setEnctype)
    Q_PROPERTY(QString enctypeString READ enctypeString)
    Q_PROPERTY(QString label READ label WRITE setLabel)
    Q_PROPERTY(CutelystForms::Form::Method method READ method WRITE setMethod)
    Q_PROPERTY(QString methodString READ methodString)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(bool novalidate READ novalidate WRITE setNovalidate)
    Q_PROPERTY(CutelystForms::Form::Target target READ target WRITE setTarget)
    Q_PROPERTY(QString targetString READ targetString)
    Q_PROPERTY(QQmlListProperty<CutelystForms::Field> fields READ fields)
    Q_PROPERTY(QMap<QString, CutelystForms::Field*> fieldById READ fieldIdMap)
    Q_PROPERTY(QMap<QString, CutelystForms::Field*> fieldByName READ fieldNameMap)
    Q_PROPERTY(QQmlListProperty<CutelystForms::Fieldset> fieldsets READ fieldsets)
    Q_PROPERTY(QMap<QString, CutelystForms::Fieldset*> fieldsetById READ fieldsetIdMap)
    Q_PROPERTY(QMap<QString, CutelystForms::Fieldset*> fieldsetByName READ fieldsetNameMap)
    Q_PROPERTY(QQmlListProperty<CutelystForms::Button> buttons READ buttons)
    Q_PROPERTY(QMap<QString, CutelystForms::Button*> buttonById READ buttonIdMap)
    Q_PROPERTY(QMap<QString, CutelystForms::Button*> buttonByName READ buttonNameMap)
    Q_CLASSINFO("DefaultProperty", "fields")
    QML_ELEMENT
public:
    explicit Form(QObject *parent = nullptr);
    ~Form() override = default;

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

    Q_REQUIRED_RESULT QStringList acceptCharset() const noexcept;
    void setAcceptCharset(const QStringList &acceptCharset) noexcept;

    Q_REQUIRED_RESULT QUrl action() const noexcept;
    void setAction(const QUrl &action) noexcept;

    Q_REQUIRED_RESULT bool autocomplete() const noexcept;
    void setAutocomplete(bool autocomplete) noexcept;

    Q_REQUIRED_RESULT QString description() const noexcept;
    void setDescription(const QString &description) noexcept;

    Q_REQUIRED_RESULT EncType enctype() const noexcept;
    void setEnctype(EncType enctype) noexcept;
    [[nodiscard]] QString enctypeString() const noexcept;

    Q_REQUIRED_RESULT QString label() const noexcept;
    void setLabel(const QString &label) noexcept;

    Q_REQUIRED_RESULT Method method() const noexcept;
    void setMethod(Method method) noexcept;
    [[nodiscard]] QString methodString() const noexcept;

    Q_REQUIRED_RESULT QString name() const noexcept;
    void setName(const QString &name) noexcept;

    Q_REQUIRED_RESULT bool novalidate() const noexcept;
    void setNovalidate(bool novalidate) noexcept;

    Q_REQUIRED_RESULT QString tagName() const noexcept override;

    Q_REQUIRED_RESULT Target target() const noexcept;
    void setTarget(Target target) noexcept;
    [[nodiscard]] QString targetString() const noexcept;

    QQmlListProperty<CutelystForms::Field> fields();
    void appendField(Field *field);
    Q_REQUIRED_RESULT QList<Field*>::size_type fieldCount() const noexcept;
    Q_REQUIRED_RESULT Field *field(QList<Field*>::size_type idx) const;
    Q_REQUIRED_RESULT Field *fieldByName(const QString &name) const;
    Q_REQUIRED_RESULT Field *fieldById(const QString &id) const;
    void clearFields();
    void replaceField(QList<Field*>::size_type idx, Field* f);
    void removeLastField();
    Q_REQUIRED_RESULT QList<Field*> fieldList() const noexcept;
    Q_REQUIRED_RESULT QMap<QString, Field*> fieldNameMap() const noexcept;
    Q_REQUIRED_RESULT QMap<QString, Field*> fieldIdMap() const noexcept;

    QQmlListProperty<CutelystForms::Fieldset> fieldsets();
    void appendFieldset(Fieldset *fieldset);
    Q_REQUIRED_RESULT QList<Fieldset*>::size_type fieldsetCount() const noexcept;
    Q_REQUIRED_RESULT Fieldset *fieldset(QList<Fieldset*>::size_type idx) const;
    Q_REQUIRED_RESULT Fieldset *fieldsetByName(const QString &name) const;
    Q_REQUIRED_RESULT Fieldset *fieldsetById(const QString &id) const;
    void clearFieldsets();
    void replaceFieldset(QList<Fieldset*>::size_type idx, Fieldset *f);
    void removeLastFieldset();
    Q_REQUIRED_RESULT QList<Fieldset*> fieldsetList() const noexcept;
    Q_REQUIRED_RESULT QMap<QString, Fieldset*> fieldsetNameMap() const noexcept;
    Q_REQUIRED_RESULT QMap<QString, Fieldset*> fieldsetIdMap() const noexcept;

    QQmlListProperty<CutelystForms::Button> buttons();
    void appendButton(Button *button);
    Q_REQUIRED_RESULT QList<Button*>::size_type buttonCount() const noexcept;
    Q_REQUIRED_RESULT Button *button(QList<Button*>::size_type idx) const;
    Q_REQUIRED_RESULT Button *buttonByName(const QString &name) const;
    Q_REQUIRED_RESULT Button *buttonById(const QString &id) const;
    void clearButtons();
    void replaceButton(QList<Button*>::size_type idx, Button *b);
    void removeLastButton();
    Q_REQUIRED_RESULT QList<Button*> buttonList() const noexcept;
    Q_REQUIRED_RESULT QMap<QString, Button*> buttonNameMap() const noexcept;
    Q_REQUIRED_RESULT QMap<QString, Button*> buttonIdMap() const noexcept;

protected:
    Form(FormPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Form)
    Q_DECLARE_PRIVATE(Form) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

QDebug operator<<(QDebug dbg, const CutelystForms::Form &form);

#endif // C_FORM_H
