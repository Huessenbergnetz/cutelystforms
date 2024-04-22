/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "searchinput_p.h"

using namespace CutelystForms;

SearchInputPrivate::SearchInputPrivate(SearchInput *q)
    : FieldPrivate{Field::Search, q}
{
}

QStringList SearchInputPrivate::attrList() const
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
    return QStringLiteral("search");
}

#include "moc_searchinput.cpp"
