/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_FIELDSET_H
#define C_FORMS_FIELDSET_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"
#include "formhtmlelement.h"

#include <QQmlListProperty>
#include <QtQml/qqmlregistration.h>

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class FieldsetPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Fieldset : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(bool disabled READ isDisabled WRITE setDisabled)
    Q_PROPERTY(QString form READ form WRITE setForm)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(QString legend READ legend WRITE setLegend)
    Q_PROPERTY(QQmlListProperty<CutelystForms::Field> fields READ fields)
    Q_PROPERTY(QList<CutelystForms::Field *> fieldList READ fieldList)
    Q_PROPERTY(QMap<QString, CutelystForms::Field *> fieldById READ fieldIdMap)
    Q_PROPERTY(QMap<QString, CutelystForms::Field *> fieldByName READ fieldNameMap)
    Q_CLASSINFO("DefaultProperty", "fields")
    QML_ELEMENT
public:
    explicit Fieldset(QObject *parent = nullptr);
    ~Fieldset() override = default;

    [[nodiscard]] bool isDisabled() const noexcept;
    void setDisabled(bool disabled) noexcept;

    [[nodiscard]] QString form() const noexcept;
    void setForm(const QString &form) noexcept;

    [[nodiscard]] QString name() const noexcept;
    void setName(const QString &name) noexcept;

    [[nodiscard]] QString description() const noexcept;
    void setDescription(const QString &description) noexcept;

    [[nodiscard]] QString legend() const noexcept;
    void setLegend(const QString &legend) noexcept;

    [[nodiscard]] QString tagName() const noexcept override;

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

protected:
    explicit Fieldset(FieldsetPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Fieldset)
    Q_DECLARE_PRIVATE(Fieldset) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_FORMS_FIELDSET_H
