/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "select_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

SelectPrivate::SelectPrivate(Select *q)
    : FieldPrivate(Field::None, q)
{
    tag = Tag::Select;
}

QStringList SelectPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (multiple) {
        lst.append(u"multiple"_s);
    }

    return lst;
}

Select::Select(QObject *parent)
    : Field(*new SelectPrivate(this), parent)
{
}

Select::Select(SelectPrivate &dd, QObject *parent)
    : Field(dd, parent)
{
}

QString Select::tagName() const noexcept
{
    return u"select"_s;
}

QString Select::tmpl() const noexcept
{
    return u"cutelystforms/select.html"_s;
}

#include "moc_select.cpp"
