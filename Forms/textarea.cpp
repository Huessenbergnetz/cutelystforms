/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "textarea_p.h"

using namespace CutelystForms;

TextareaPrivate::TextareaPrivate(Textarea *q)
    : FieldPrivate(Field::None, q)
{
    tag = Tag::Textarea;
}

QStringList TextareaPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (maxlength > -1) {
        lst.append(u"maxlength=\""_qs + QString::number(maxlength) + QLatin1Char('"'));
    }

    if (minlength > -1) {
        lst.append(u"minlength=\""_qs + QString::number(minlength) + QLatin1Char('"'));
    }

    if (!placeholder.isEmpty()) {
        lst.append(u"placeholder=\""_qs + placeholder + QLatin1Char('"'));
    }

    if (readonly) {
        lst.append(u"readonly"_qs);
    }

    return lst;
}

Textarea::Textarea(QObject *parent)
    : Field(*new TextareaPrivate(this), parent)
{
}

Textarea::Textarea(TextareaPrivate &dd, QObject *parent)
    : Field(dd, parent)
{
}

QString Textarea::tagName() const noexcept
{
    return QStringLiteral("textarea");
}

#include "moc_textarea.cpp"
