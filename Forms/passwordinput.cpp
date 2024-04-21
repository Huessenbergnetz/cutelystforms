/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "passwordinput_p.h"

using namespace CutelystForms;

PasswordInputPrivate::PasswordInputPrivate(PasswordInput *q)
    : FieldPrivate{Field::Password, q}
{
}

PasswordInput::PasswordInput(QObject *parent)
    : Field{*new PasswordInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type PasswordInput::type() const noexcept
{
    return Field::Password;
}

QString PasswordInput::typeString() const noexcept
{
    return QStringLiteral("password");
}

#include "moc_passwordinput.cpp"
