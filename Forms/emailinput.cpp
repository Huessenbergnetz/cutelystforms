/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "emailinput_p.h"

using namespace CutelystForms;

EmailInputPrivate::EmailInputPrivate(EmailInput *q)
    : InputPrivate{q}
{

}

EmailInput::EmailInput(QObject *parent)
    : Input{* new EmailInputPrivate{this}, parent}
{

}

QString EmailInput::value() const noexcept
{
    Q_D(const EmailInput);
    return d->value;
}

void EmailInput::setValue(const QString &value) noexcept
{
    Q_D(EmailInput);
    d->value = value;
}

CutelystForms::Input::Type EmailInput::type() const noexcept
{
    return Input::Email;
}

QString EmailInput::typeString() const noexcept
{
    return QStringLiteral("email");
}

QString EmailInput::valueString() const noexcept
{
    Q_D(const EmailInput);
    return d->value;
}
