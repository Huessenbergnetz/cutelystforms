/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "textinput_p.h"

using namespace CutelystForms;

TextInputPrivate::TextInputPrivate(TextInput *q)
    : FieldPrivate(Field::Text, q)
{

}

TextInput::TextInput(QObject *parent)
    : Field{* new TextInputPrivate{this}, parent}
{

}

CutelystForms::Field::Type TextInput::type() const noexcept
{
    return Field::Text;
}

QString TextInput::typeString() const noexcept
{
    return QStringLiteral("text");
}

#include "moc_textinput.cpp"
