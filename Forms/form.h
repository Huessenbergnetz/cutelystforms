/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORM_H
#define C_FORM_H

#include "button.h"
#include "cutelyst_plugin_forms_export.h"
#include "field.h"
#include "fieldset.h"
#include "formhtmlelement.h"

#include <Cutelyst/ParamsMultiMap>

#include <QQmlListProperty>
#include <QUrl>
#include <QtQml/qqmlregistration.h>

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
    Q_PROPERTY(QList<CutelystForms::Field *> fieldList READ fieldList)
    Q_PROPERTY(QMap<QString, CutelystForms::Field *> fieldById READ fieldIdMap)
    Q_PROPERTY(QMap<QString, CutelystForms::Field *> fieldByName READ fieldNameMap)

    Q_PROPERTY(QQmlListProperty<CutelystForms::Fieldset> fieldsets READ fieldsets)
    Q_PROPERTY(QList<CutelystForms::Fieldset *> fieldsetList READ fieldsetList)
    Q_PROPERTY(QMap<QString, CutelystForms::Fieldset *> fieldsetById READ fieldsetIdMap)
    Q_PROPERTY(QMap<QString, CutelystForms::Fieldset *> fieldsetByName READ fieldsetNameMap)

    Q_PROPERTY(QQmlListProperty<CutelystForms::Button> buttons READ buttons)
    Q_PROPERTY(QList<CutelystForms::Button *> buttonList READ buttonList)
    Q_PROPERTY(QMap<QString, CutelystForms::Button *> buttonById READ buttonIdMap)
    Q_PROPERTY(QMap<QString, CutelystForms::Button *> buttonByName READ buttonNameMap)
    Q_CLASSINFO("DefaultProperty", "fields")
    QML_ELEMENT
public:
    explicit Form(QObject *parent = nullptr);
    ~Form() override = default;

    enum EncType { WwwFormUrlEncoded = 0, MultipartFormData, TextPlain };
    Q_ENUM(EncType)

    enum Method { Post = 0, Get };
    Q_ENUM(Method)

    enum Target { Self = 0, Blank, Parent, Top };
    Q_ENUM(Target)

    [[nodiscard]] QStringList acceptCharset() const noexcept;
    void setAcceptCharset(const QStringList &acceptCharset);

    [[nodiscard]] QUrl action() const noexcept;
    void setAction(const QUrl &action) noexcept;

    [[nodiscard]] bool autocomplete() const noexcept;
    void setAutocomplete(bool autocomplete) noexcept;

    [[nodiscard]] QString description() const noexcept;
    void setDescription(const QString &description) noexcept;

    [[nodiscard]] EncType enctype() const noexcept;
    void setEnctype(EncType enctype) noexcept;
    [[nodiscard]] QString enctypeString() const noexcept;

    [[nodiscard]] QString label() const noexcept;
    void setLabel(const QString &label) noexcept;

    [[nodiscard]] Method method() const noexcept;
    void setMethod(Method method) noexcept;
    [[nodiscard]] QString methodString() const noexcept;

    [[nodiscard]] QString name() const noexcept;
    void setName(const QString &name) noexcept;

    [[nodiscard]] bool novalidate() const noexcept;
    void setNovalidate(bool novalidate) noexcept;

    /*!
     * \brief Sets \a errors to each field in the form.
     *
     * The \a errors hash has to contain the errors for each field identified by the field name
     * as the key.
     * This can for example easily be used with Cutelyst::ValidatorResult::errors().
     */
    void setErrors(const QHash<QString, QStringList> &errors);

    /*!
     * \brief Sets the value for each field from the \a valueMap.
     *
     * Can for example be used to fill the values from the input parameters. The key of the
     * \a valueMap has to be the field name.
     */
    void setValues(const Cutelyst::ParamsMultiMap &valueMap);
    /*!
     * \brief Sets the value for each field from the \a valueMap.
     *
     * Can for example be used to fill the values from the Cutelyst::ValidatorResult::values().
     * The key of the \a valueMap has to be the field name.
     */
    void setValues(const QVariantHash &valueMap);

    void setAsChecked(const QStringList &checked);

    inline void setAsChecked(const Cutelyst::ParamsMultiMap &valueMap);

    inline void setAsChecked(const QVariantHash &valueMap);

    [[nodiscard]] QString tagName() const noexcept override;

    [[nodiscard]] Target target() const noexcept;
    void setTarget(Target target) noexcept;
    [[nodiscard]] QString targetString() const noexcept;

    QQmlListProperty<CutelystForms::Field> fields();
    void appendField(Field *field);
    void appendFields(const QList<Field *> &fields);
    [[nodiscard]] QList<Field *>::size_type fieldCount() const noexcept;
    [[nodiscard]] Field *field(QList<Field *>::size_type idx) const;
    [[nodiscard]] Field *fieldByName(const QString &name) const;
    [[nodiscard]] Field *fieldById(const QString &id) const;
    void clearFields();
    void replaceField(QList<Field *>::size_type idx, Field *f);
    void removeLastField();
    [[nodiscard]] QList<Field *> fieldList() const noexcept;
    [[nodiscard]] QMap<QString, Field *> fieldNameMap() const noexcept;
    [[nodiscard]] QMap<QString, Field *> fieldIdMap() const noexcept;

    QQmlListProperty<CutelystForms::Fieldset> fieldsets();
    void appendFieldset(Fieldset *fieldset);
    void appendFieldsets(const QList<Fieldset *> &fieldsets);
    [[nodiscard]] QList<Fieldset *>::size_type fieldsetCount() const noexcept;
    [[nodiscard]] Fieldset *fieldset(QList<Fieldset *>::size_type idx) const;
    [[nodiscard]] Fieldset *fieldsetByName(const QString &name) const;
    [[nodiscard]] Fieldset *fieldsetById(const QString &id) const;
    void clearFieldsets();
    void replaceFieldset(QList<Fieldset *>::size_type idx, Fieldset *f);
    void removeLastFieldset();
    [[nodiscard]] QList<Fieldset *> fieldsetList() const noexcept;
    [[nodiscard]] QMap<QString, Fieldset *> fieldsetNameMap() const noexcept;
    [[nodiscard]] QMap<QString, Fieldset *> fieldsetIdMap() const noexcept;

    QQmlListProperty<CutelystForms::Button> buttons();
    void appendButton(Button *button);
    void appendButtons(const QList<Button *> &buttons);
    [[nodiscard]] QList<Button *>::size_type buttonCount() const noexcept;
    [[nodiscard]] Button *button(QList<Button *>::size_type idx) const;
    [[nodiscard]] Button *buttonByName(const QString &name) const;
    [[nodiscard]] Button *buttonById(const QString &id) const;
    void clearButtons();
    void replaceButton(QList<Button *>::size_type idx, Button *b);
    void removeLastButton();
    [[nodiscard]] QList<Button *> buttonList() const noexcept;
    [[nodiscard]] QMap<QString, Button *> buttonNameMap() const noexcept;
    [[nodiscard]] QMap<QString, Button *> buttonIdMap() const noexcept;

protected:
    explicit Form(FormPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Form)
    Q_DECLARE_PRIVATE(Form) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

inline void Form::setAsChecked(const Cutelyst::ParamsMultiMap &valueMap)
{
    setAsChecked(valueMap.keys());
}

inline void Form::setAsChecked(const QVariantHash &valueMap)
{
    setAsChecked(valueMap.keys());
}

} // namespace CutelystForms

QDebug operator<<(QDebug dbg, const CutelystForms::Form &form);

#endif // C_FORM_H
