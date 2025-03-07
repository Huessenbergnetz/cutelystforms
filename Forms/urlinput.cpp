/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "urlinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

UrlInputPrivate::UrlInputPrivate(UrlInput *q)
    : FieldPrivate{Field::Url, q}
{
}

QStringList UrlInputPrivate::attrList() const
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

QString UrlInputPrivate::getValueString() const
{
    if (value.canConvert<QUrl>()) {
        return value.toUrl().toString(QUrl::FullyEncoded);
    }

    return value.toString();
}

UrlInput::UrlInput(QObject *parent)
    : Field{*new UrlInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type UrlInput::type() const noexcept
{
    return Field::Url;
}

QString UrlInput::typeString() const noexcept
{
    return u"url"_s;
}

#include "moc_urlinput.cpp"
