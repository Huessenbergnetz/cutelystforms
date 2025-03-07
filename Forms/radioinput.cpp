/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "radioinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

RadioInputPrivate::RadioInputPrivate(RadioInput *q)
    : FieldPrivate(Field::Radio, q)
{
}

QStringList RadioInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (checked) {
        lst.append(u"checked"_s);
    }

    return lst;
}

RadioInput::RadioInput(QObject *parent)
    : Field{*new RadioInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type RadioInput::type() const noexcept
{
    return Field::Radio;
}

QString RadioInput::typeString() const noexcept
{
    return u"radio"_s;
}

#include "moc_radioinput.cpp"
