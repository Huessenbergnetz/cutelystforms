/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "option_p.h"

using namespace CutelystForms;

OptionPrivate::OptionPrivate(Option *q) :
    SelectContentPrivate(q)
{

}

Option::Option(QObject *parent) :
    SelectContent(* new OptionPrivate(this), parent)
{

}

Option::Option(OptionPrivate &dd, QObject *parent) :
    SelectContent(dd, parent)
{

}

bool Option::isSelected() const noexcept
{
    Q_D(const Option);
    return d->selected;
}

void Option::setSelected(bool selected) noexcept
{
    Q_D(Option);
    d->selected = selected;
}

QString Option::text() const noexcept
{
    Q_D(const Option);
    return d->text;
}

void Option::setText(const QString &text) noexcept
{
    Q_D(Option);
    d->text = text;
}

QString Option::value() const noexcept
{
    Q_D(const Option);
    return d->value;
}

void Option::setValue(const QString &value) noexcept
{
    Q_D(Option);
    d->value = value;
}

#include "moc_option.cpp"
