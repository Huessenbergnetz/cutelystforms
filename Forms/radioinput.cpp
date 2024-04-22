/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "radioinput_p.h"

using namespace CutelystForms;

RadioInputPrivate::RadioInputPrivate(RadioInput *q)
    : FieldPrivate(Field::Radio, q)
{
}

QStringList RadioInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (checked) {
        lst.append(u"checked"_qs);
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
    return QStringLiteral("radio");
}

#include "moc_radioinput.cpp"
