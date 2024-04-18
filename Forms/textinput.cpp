/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "textinput_p.h"

using namespace CutelystForms;

TextInputPrivate::TextInputPrivate(TextInput *q)
    : InputPrivate(q)
{

}

TextInput::TextInput(QObject *parent)
    : Input{* new TextInputPrivate{this}, parent}
{

}

QString TextInput::value() const noexcept
{
    Q_D(const TextInput);
    return d->value;
}

void TextInput::setValue(const QString &value) noexcept
{
    Q_D(TextInput);
    d->value = value;
}

CutelystForms::Input::Type TextInput::type() const noexcept
{
    return Input::Text;
}

QString TextInput::typeString() const noexcept
{
    return QStringLiteral("text");
}

QString TextInput::valueString() const noexcept
{
    Q_D(const TextInput);
    return d->value;
}

#include "moc_textinput.cpp"
