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
