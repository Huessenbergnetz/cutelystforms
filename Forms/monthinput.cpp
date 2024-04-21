/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "monthinput_p.h"

using namespace CutelystForms;

MonthInputPrivate::MonthInputPrivate(MonthInput *q)
    : FieldPrivate{Field::Month, q}
{
}

MonthInput::MonthInput(QObject *parent)
    : Field{*new MonthInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type MonthInput::type() const noexcept
{
    return Field::Month;
}

QString MonthInput::typeString() const noexcept
{
    return QStringLiteral("month");
}

#include "moc_monthinput.cpp"
