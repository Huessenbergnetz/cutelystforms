/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "telinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

TelInputPrivate::TelInputPrivate(TelInput *q)
    : FieldPrivate{Field::Tel, q}
{
}

QStringList TelInputPrivate::attrList() const
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

    if (readonly) {
        lst.append(u"readonly"_s);
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
    return u"tel"_s;
}

#include "moc_telinput.cpp"
