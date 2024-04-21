/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "telinput_p.h"

using namespace CutelystForms;

TelInputPrivate::TelInputPrivate(TelInput *q)
    : FieldPrivate{Field::Tel, q}
{
}

TelInput::TelInput(QObject *parent)
    : Field{*new TelInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type TelInput::type() const noexcept
{
    return Field::Tel;
}

QString TelInput::typeString() const noexcept
{
    return QStringLiteral("tel");
}

#include "moc_telinput.cpp"
