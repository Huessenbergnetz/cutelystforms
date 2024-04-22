/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "telinput_p.h"

using namespace CutelystForms;

TelInputPrivate::TelInputPrivate(TelInput *q)
    : FieldPrivate{Field::Tel, q}
{
}

QStringList TelInputPrivate::attrList() const
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

    if (readonly) {
        lst.append(u"readonly"_qs);
    }

    return lst;
}

TelInput::TelInput(QObject *parent)
    : Field{*new TelInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type TelInput::type() const noexcept
{
    return Field::Tel;
}

QString TelInput::typeString() const noexcept
{
    return QStringLiteral("tel");
}

#include "moc_telinput.cpp"
