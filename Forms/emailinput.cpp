/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "emailinput_p.h"

using namespace CutelystForms;

EmailInputPrivate::EmailInputPrivate(EmailInput *q)
    : FieldPrivate{Field::Email, q}
{
}

EmailInput::EmailInput(QObject *parent)
    : Field{*new EmailInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type EmailInput::type() const noexcept
{
    return Field::Email;
}

QString EmailInput::typeString() const noexcept
{
    return QStringLiteral("email");
}

#include "moc_emailinput.cpp"
