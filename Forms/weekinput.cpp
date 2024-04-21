/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "weekinput_p.h"

using namespace CutelystForms;

WeekInputPrivate::WeekInputPrivate(WeekInput *q)
    : FieldPrivate{Field::Week, q}
{
}

WeekInput::WeekInput(QObject *parent)
    : Field{*new WeekInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type WeekInput::type() const noexcept
{
    return Field::Week;
}

QString WeekInput::typeString() const noexcept
{
    return QStringLiteral("week");
}

#include "moc_weekinput.cpp"
