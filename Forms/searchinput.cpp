/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "searchinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

SearchInputPrivate::SearchInputPrivate(SearchInput *q)
    : FieldPrivate{Field::Search, q}
{
}

QStringList SearchInputPrivate::attrList() const
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

SearchInput::SearchInput(QObject *parent)
    : Field{*new SearchInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type SearchInput::type() const noexcept
{
    return Field::Search;
}

QString SearchInput::typeString() const noexcept
{
    return u"search"_s;
}

#include "moc_searchinput.cpp"
