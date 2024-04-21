/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "datetimelocalinput_p.h"

using namespace CutelystForms;

DateTimeLocalInputPrivate::DateTimeLocalInputPrivate(DateTimeLocalInput *q)
    : FieldPrivate{Field::DateTimeLocal, q}
{
}

DateTimeLocalInput::DateTimeLocalInput(QObject *parent)
    : Field{*new DateTimeLocalInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type DateTimeLocalInput::type() const noexcept
{
    return Field::DateTimeLocal;
}

QString DateTimeLocalInput::typeString() const noexcept
{
    return QStringLiteral("datetime-local");
}

#include "moc_datetimelocalinput.cpp"
