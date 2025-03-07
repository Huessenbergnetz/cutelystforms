/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "numberinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

NumberInputPrivate::NumberInputPrivate(NumberInput *q)
    : FieldPrivate(Field::Number, q)
{
}

QStringList NumberInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (!list.isEmpty()) {
        lst.append(u"list=\""_s + list + '"'_L1);
    }

    if (!max.isNull()) {
        lst.append(u"max=\""_s + max.toString() + '"'_L1);
    }

    if (!min.isNull()) {
        lst.append(u"min=\""_s + min.toString() + '"'_L1);
    }

    if (!step.isNull()) {
        lst.append(u"step=\""_s + step.toString() + '"'_L1);
    }

    if (!placeholder.isEmpty()) {
        lst.append(u"placeholder=\""_s + placeholder + '"'_L1);
    }

    if (readonly) {
        lst.append(u"readonly"_s);
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
    return u"number"_s;
}

#include "moc_numberinput.cpp"
