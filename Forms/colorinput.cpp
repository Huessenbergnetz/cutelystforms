/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "colorinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

ColorInputPrivate::ColorInputPrivate(ColorInput *q)
    : FieldPrivate(Field::Color, q)
{
}

QStringList ColorInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (!list.isEmpty()) {
        lst.append(u"list=\""_s + list + '"'_L1);
    }

    return lst;
}

ColorInput::ColorInput(QObject *parent)
    : Field{*new ColorInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type ColorInput::type() const noexcept
{
    return Field::Color;
}

QString ColorInput::typeString() const noexcept
{
    return u"color"_s;
}

#include "moc_colorinput.cpp"
