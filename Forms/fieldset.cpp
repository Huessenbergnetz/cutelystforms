/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fieldset_p.h"

using namespace CutelystForms;

FieldsetPrivate::FieldsetPrivate(Fieldset *q) :
    FormHtmlElementPrivate(q)
{

}

Fieldset::Fieldset(QObject *parent) :
    FormHtmlElement(* new FieldsetPrivate(this), parent)
{

}

Fieldset::Fieldset(FieldsetPrivate &dd, QObject *parent) :
    FormHtmlElement(dd, parent)
{

}

bool Fieldset::isDisabled() const noexcept
{
    Q_D(const Fieldset);
    return d->disabled;
}

void Fieldset::setDisabled(bool disabled) noexcept
{
    Q_D(Fieldset);
    d->disabled = disabled;
}

QString Fieldset::form() const noexcept
{
    Q_D(const Fieldset);
    return d->form;
}

void Fieldset::setForm(const QString &form) noexcept
{
    Q_D(Fieldset);
    d->form = form;
}

QString Fieldset::name() const noexcept
{
    Q_D(const Fieldset);
    return d->name;
}

void Fieldset::setName(const QString &name) noexcept
{
    Q_D(Fieldset);
    d->name = name;
}

QString Fieldset::description() const noexcept
{
    Q_D(const Fieldset);
    return d->description;
}

void Fieldset::setDescription(const QString &description) noexcept
{
    Q_D(Fieldset);
    d->description = description;
}

CutelystForms::Legend* Fieldset::legend() const noexcept
{
    Q_D(const Fieldset);
    return d->legend;
}

void Fieldset::setLegend(CutelystForms::Legend *legend) noexcept
{
    Q_D(Fieldset);
    d->legend = legend;
}

QString Fieldset::tagName() const noexcept
{
    return QStringLiteral("fieldset");
}

QQmlListProperty<CutelystForms::Field> Fieldset::fields()
{
    Q_D(Fieldset);
    return {this, &d->fields};
}

void Fieldset::appendField(Field *field)
{
    Q_D(Fieldset);
    d->fields.push_back(field);
}

QList<Field*>::size_type Fieldset::fieldCount() const noexcept
{
    Q_D(const Fieldset);
    return d->fields.size();
}

Field* Fieldset::field(QList<Field*>::size_type idx) const
{
    Q_D(const Fieldset);
    if (idx < d->fields.size()) {
        return d->fields.at(idx);
    } else {
        return nullptr;
    }
}

void Fieldset::clearFields()
{
    Q_D(Fieldset);
    qDeleteAll(d->fields);
    d->fields.clear();
}

QList<Field*> Fieldset::fieldList() const noexcept
{
    Q_D(const Fieldset);
    return d->fields;
}

#include "moc_fieldset.cpp"
