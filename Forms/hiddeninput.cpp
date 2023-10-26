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

CutelystForms::Input::Type HiddenInput::type() const noexcept
{
    return Input::Hidden;
}

QString HiddenInput::typeString() const noexcept
{
    return QStringLiteral("hidden");
}

#include "moc_hiddeninput.cpp"
