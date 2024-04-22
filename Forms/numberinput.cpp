/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "numberinput_p.h"

using namespace CutelystForms;

NumberInputPrivate::NumberInputPrivate(NumberInput *q)
    : FieldPrivate(Field::Number, q)
{
}

QStringList NumberInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (!list.isEmpty()) {
        lst.append(u"list=\""_qs + list + QLatin1Char('"'));
    }

    if (!max.isNull()) {
        lst.append(u"max\""_qs + max.toString() + QLatin1Char('"'));
    }

    if (!min.isNull()) {
        lst.append(u"min=\""_qs + min.toString() + QLatin1Char('"'));
    }

    if (!step.isNull()) {
        lst.append(u"step=\""_qs + step.toString() + QLatin1Char('"'));
    }

    if (!placeholder.isEmpty()) {
        lst.append(u"placeholder=\""_qs + placeholder + QLatin1Char('"'));
    }

    if (readonly) {
        lst.append(u"readonly"_qs);
    }

    return lst;
}

NumberInput::NumberInput(QObject *parent)
    : Field{*new NumberInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type NumberInput::type() const noexcept
{
    return Field::Number;
}

QString NumberInput::typeString() const noexcept
{
    return QStringLiteral("number");
}

#include "moc_numberinput.cpp"
