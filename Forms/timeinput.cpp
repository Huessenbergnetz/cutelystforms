/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "timeinput_p.h"

using namespace CutelystForms;

TimeInputPrivate::TimeInputPrivate(TimeInput *q)
    : FieldPrivate{Field::Time, q}
{
}

TimeInput::TimeInput(QObject *parent)
    : Field{*new TimeInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type TimeInput::type() const noexcept
{
    return Field::Time;
}

QString TimeInput::typeString() const noexcept
{
    return QStringLiteral("time");
}

#include "moc_timeinput.cpp"
