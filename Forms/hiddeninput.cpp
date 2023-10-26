/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hiddeninput_p.h"

using namespace CutelystForms;

HiddenInputPrivate::HiddenInputPrivate(HiddenInput *q) :
    InputPrivate{q}
{

}

HiddenInput::HiddenInput(QObject *parent) :
    Input{* new HiddenInputPrivate{this}, parent}
{

}

QString HiddenInput::value() const noexcept
{
    Q_D(const HiddenInput);
    return d->value;
}

void HiddenInput::setValue(const QString &value) noexcept
{
    Q_D(HiddenInput);
    d->value = value;
}

CutelystForms::Input::Type HiddenInput::type() const noexcept
{
    return Input::Hidden;
}

QString HiddenInput::typeString() const noexcept
{
    return QStringLiteral("hidden");
}

QString HiddenInput::valueString() const noexcept
{
    Q_D(const HiddenInput);
    return d->value;
}

#include "moc_hiddeninput.cpp"
