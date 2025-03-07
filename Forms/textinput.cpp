/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "textinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

TextInputPrivate::TextInputPrivate(TextInput *q)
    : FieldPrivate(Field::Text, q)
{
}

QStringList TextInputPrivate::attrList() const
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
    return u"text"_s;
}

#include "moc_textinput.cpp"
