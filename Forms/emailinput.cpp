/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "emailinput_p.h"

using namespace CutelystForms;

EmailInputPrivate::EmailInputPrivate(EmailInput *q)
    : FieldPrivate{Field::Email, q}
{
}

QStringList EmailInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (!list.isEmpty()) {
        lst.append(u"list=\""_qs + list + QLatin1Char('"'));
    }

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

    if (multiple) {
        lst.append(u"multiple"_qs);
    }

    if (readonly) {
        lst.append(u"readonly"_qs);
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
    return QStringLiteral("email");
}

#include "moc_emailinput.cpp"
