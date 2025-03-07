/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "emailinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

EmailInputPrivate::EmailInputPrivate(EmailInput *q)
    : FieldPrivate{Field::Email, q}
{
}

QStringList EmailInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (!list.isEmpty()) {
        lst.append(u"list=\""_s + list + '"'_L1);
    }

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

    if (multiple) {
        lst.append(u"multiple"_s);
    }

    if (readonly) {
        lst.append(u"readonly"_s);
    }

    return lst;
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
    return u"email"_s;
}

#include "moc_emailinput.cpp"
