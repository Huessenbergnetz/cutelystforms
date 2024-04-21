/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "urlinput_p.h"

using namespace CutelystForms;

UrlInputPrivate::UrlInputPrivate(UrlInput *q)
    : FieldPrivate{Field::Url, q}
{
}

UrlInput::UrlInput(QObject *parent)
    : Field{*new UrlInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type UrlInput::type() const noexcept
{
    return Field::Url;
}

QString UrlInput::typeString() const noexcept
{
    return QStringLiteral("url");
}

#include "moc_urlinput.cpp"
