/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "input_p.h"

using namespace CutelystForms;

InputPrivate::InputPrivate(Input *q) :
    FieldPrivate{q}
{

}

Input::Input(QObject *parent) :
    Field{* new InputPrivate{this}, parent}
{

}

Input::Input(InputPrivate &dd, QObject *parent) :
    Field{dd, parent}
{

}

CutelystForms::Input::Type Input::type() const noexcept
{
    return Text;
}

QString Input::typeString() const noexcept
{
    return QStringLiteral("text");
}

QString Input::valueString() const noexcept
{
    return {};
}

QString Input::tagName() const noexcept
{
    return QStringLiteral("input");
}

#include "moc_input.cpp"
