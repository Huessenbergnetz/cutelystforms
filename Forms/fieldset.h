/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_FIELDSET_H
#define C_FORMS_FIELDSET_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"
#include "legend.h"
#include "field.h"
#include <QObject>
#include <QQmlListProperty>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

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
    Q_PROPERTY(CutelystForms::Legend* legend READ legend WRITE setLegend)
    Q_PROPERTY(QQmlListProperty<CutelystForms::Field> fields READ fields)
    Q_PROPERTY(QMap<QString, CutelystForms::Field*> fieldById READ fieldIdMap)
    Q_PROPERTY(QMap<QString, CutelystForms::Field*> fieldByName READ fieldNameMap)
    Q_CLASSINFO("DefaultProperty", "fields")
    QML_ELEMENT
public:
    explicit Fieldset(QObject *parent = nullptr);
    ~Fieldset() override = default;

    Q_REQUIRED_RESULT bool isDisabled() const noexcept;
    void setDisabled(bool disabled) noexcept;

    Q_REQUIRED_RESULT QString form() const noexcept;
    void setForm(const QString &form) noexcept;

    Q_REQUIRED_RESULT QString name() const noexcept;
    void setName(const QString &name) noexcept;

    Q_REQUIRED_RESULT QString description() const noexcept;
    void setDescription(const QString &description) noexcept;

    Q_REQUIRED_RESULT Legend* legend() const noexcept;
    void setLegend(Legend *legend) noexcept;

    Q_REQUIRED_RESULT QString tagName() const noexcept override;

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

protected:
    Fieldset(FieldsetPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Fieldset)
    Q_DECLARE_PRIVATE(Fieldset) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_FIELDSET_H
