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
    Q_CLASSINFO("DefaultProperty", "fields")
    QML_ELEMENT
public:
    explicit Fieldset(QObject *parent = nullptr);
    virtual ~Fieldset() override;

    bool isDisabled() const;
    void setDisabled(bool disabled);

    QString form() const;
    void setForm(const QString &form);

    QString name() const;
    void setName(const QString &name);

    QString description() const;
    void setDescription(const QString &description);

    Legend* legend() const;
    void setLegend(Legend *legend);

    QQmlListProperty<CutelystForms::Field> fields();
    void appendField(Field *field);
    QList<Field*>::size_type fieldCount() const;
    Field *field(QList<Field*>::size_type idx) const;
    void clearFields();
    QList<Field*> fieldList() const;

protected:
    Fieldset(FieldsetPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Fieldset)
    Q_DECLARE_PRIVATE(Fieldset)
};

}

#endif // C_FORMS_FIELDSET_H
