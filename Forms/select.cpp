/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "select_p.h"

using namespace CutelystForms;

SelectPrivate::SelectPrivate(Select *q)
    : FieldPrivate(Field::None, q)
{
    tag = Tag::Select;
}

QStringList SelectPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (multiple) {
        lst.append(u"multiple"_qs);
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
    return QStringLiteral("select");
}

#include "moc_select.cpp"
