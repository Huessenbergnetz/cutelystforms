/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "field_p.h"

using namespace CutelystForms;

FieldPrivate::FieldPrivate(Field *q) :
    FormHtmlElementPrivate(q)
{

}

Field::Field(QObject *parent) :
    FormHtmlElement(* new FieldPrivate(this), parent)
{

}

Field::Field(FieldPrivate &dd, QObject *parent) :
    FormHtmlElement(dd, parent)
{

}

QString Field::name() const noexcept
{
    Q_D(const Field);
    return d->name;
}

void Field::setName(const QString &name) noexcept
{
    Q_D(Field);
    d->name = name;
}

QString Field::label() const noexcept
{
    Q_D(const Field);
    return d->label;
}

void Field::setLabel(const QString &label) noexcept
{
    Q_D(Field);
    d->label = label;
}

QString Field::description() const noexcept
{
    Q_D(const Field);
    return d->description;
}

void Field::setDescription(const QString &description) noexcept
{
    Q_D(Field);
    d->description = description;
}

bool Field::required() const noexcept
{
    Q_D(const Field);
    return d->required;
}

void Field::setRequired(bool required) noexcept
{
    Q_D(Field);
    d->required = required;
}

QString Field::autocomplete() const noexcept
{
    Q_D(const Field);
    return d->autocomplete;
}

void Field::setAutocomplete(const QString &autocomplete) noexcept
{
    Q_D(Field);
    d->autocomplete = autocomplete;
}

#include "moc_field.cpp"
