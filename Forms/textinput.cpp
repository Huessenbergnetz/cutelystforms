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

QStringList TextInputPrivate::attrList() const
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

TextInput::TextInput(QObject *parent)
    : Field{*new TextInputPrivate{this}, parent}
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
