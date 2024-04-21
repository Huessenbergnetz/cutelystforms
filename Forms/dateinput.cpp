/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "dateinput_p.h"

using namespace CutelystForms;

DateInputPrivate::DateInputPrivate(DateInput *q)
    : FieldPrivate{Field::Date, q}
{
}

DateInput::DateInput(QObject *parent)
    : Field{*new DateInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type DateInput::type() const noexcept
{
    return Field::Date;
}

QString DateInput::typeString() const noexcept
{
    return QStringLiteral("date");
}

#include "moc_dateinput.cpp"
