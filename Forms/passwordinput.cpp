/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "passwordinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

PasswordInputPrivate::PasswordInputPrivate(PasswordInput *q)
    : FieldPrivate{Field::Password, q}
{
}

QStringList PasswordInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (maxlength > -1) {
        lst.append(u"maxlength=\""_s + QString::number(maxlength) + '"'_L1);
    }

    if (minlength > -1) {
        lst.append(u"minlength=\""_s + QString::number(minlength) + '"'_L1);
    }

    if (!pattern.isEmpty()) {
        lst.append(u"pattern=\""_s + pattern + '"'_L1);
    }

    if (!placeholder.isEmpty()) {
        lst.append(u"placeholder=\""_s + placeholder + '"'_L1);
    }

    if (readonly) {
        lst.append(u"readonly"_s);
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
    return u"password"_s;
}

#include "moc_passwordinput.cpp"
