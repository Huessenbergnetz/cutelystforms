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

QStringList PasswordInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (maxlength > -1) {
        lst.append(u"maxlength=\""_qs + QString::number(maxlength) + QLatin1Char('"'));
    }

    if (minlength > -1) {
        lst.append(u"minlength=\""_qs + QString::number(minlength) + QLatin1Char('"'));
    }

    if (!pattern.isEmpty()) {
        lst.append(u"pattern=\""_qs + pattern + QLatin1Char('"'));
    }

    if (!placeholder.isEmpty()) {
        lst.append(u"placeholder=\""_qs + placeholder + QLatin1Char('"'));
    }

    if (readonly) {
        lst.append(u"readonly"_qs);
    }

    return lst;
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
