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

Fieldset::~Fieldset()
{

}

bool Fieldset::isDisabled() const
{
    Q_D(const Fieldset);
    return d->disabled;
}

void Fieldset::setDisabled(bool disabled)
{
    Q_D(Fieldset);
    d->disabled = disabled;
}

QString Fieldset::form() const
{
    Q_D(const Fieldset);
    return d->form;
}

void Fieldset::setForm(const QString &form)
{
    Q_D(Fieldset);
    d->form = form;
}

QString Fieldset::name() const
{
    Q_D(const Fieldset);
    return d->name;
}

void Fieldset::setName(const QString &name)
{
    Q_D(Fieldset);
    d->name = name;
}

QString Fieldset::description() const
{
    Q_D(const Fieldset);
    return d->description;
}

void Fieldset::setDescription(const QString &description)
{
    Q_D(Fieldset);
    d->description = description;
}

CutelystForms::Legend* Fieldset::legend() const
{
    Q_D(const Fieldset);
    return d->legend;
}

void Fieldset::setLegend(CutelystForms::Legend *legend)
{
    Q_D(Fieldset);
    d->legend = legend;
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

QList<Field*>::size_type Fieldset::fieldCount() const
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

QList<Field*> Fieldset::fieldList() const
{
    Q_D(const Fieldset);
    return d->fields;
}

#include "moc_fieldset.cpp"
