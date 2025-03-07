/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "rangeinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

RangeInputPrivate::RangeInputPrivate(RangeInput *q)
    : FieldPrivate(Field::Range, q)
{
}

QStringList RangeInputPrivate::attrList() const
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
    return u"range"_s;
}

#include "moc_rangeinput.cpp"
