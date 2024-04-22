/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "rangeinput_p.h"

using namespace CutelystForms;

RangeInputPrivate::RangeInputPrivate(RangeInput *q)
    : FieldPrivate(Field::Range, q)
{
}

QStringList RangeInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (!list.isEmpty()) {
        lst.append(u"list=\""_qs + list + QLatin1Char('"'));
    }

    if (!max.isNull()) {
        lst.append(u"max=\""_qs + max.toString() + QLatin1Char('"'));
    }

    if (!min.isNull()) {
        lst.append(u"min=\""_qs + min.toString() + QLatin1Char('"'));
    }

    if (!step.isNull()) {
        lst.append(u"step=\""_qs + step.toString() + QLatin1Char('"'));
    }

    return lst;
}

RangeInput::RangeInput(QObject *parent)
    : Field{*new RangeInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type RangeInput::type() const noexcept
{
    return Field::Range;
}

QString RangeInput::typeString() const noexcept
{
    return QStringLiteral("range");
}

#include "moc_rangeinput.cpp"
