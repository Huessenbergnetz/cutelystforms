/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "textarea_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

TextareaPrivate::TextareaPrivate(Textarea *q)
    : FieldPrivate(Field::None, q)
{
    tag = Tag::Textarea;
}

QStringList TextareaPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (maxlength > -1) {
        lst.append(u"maxlength=\""_s + QString::number(maxlength) + '"'_L1);
    }

    if (minlength > -1) {
        lst.append(u"minlength=\""_s + QString::number(minlength) + '"'_L1);
    }

    if (!placeholder.isEmpty()) {
        lst.append(u"placeholder=\""_s + placeholder + '"'_L1);
    }

    if (readonly) {
        lst.append(u"readonly"_s);
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
    return u"textarea"_s;
}

QString Textarea::tmpl() const noexcept
{
    return u"cutelystforms/textarea.html"_s;
}

#include "moc_textarea.cpp"
