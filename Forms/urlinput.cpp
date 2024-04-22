/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "urlinput_p.h"

using namespace CutelystForms;

UrlInputPrivate::UrlInputPrivate(UrlInput *q)
    : FieldPrivate{Field::Url, q}
{
}

QStringList UrlInputPrivate::attrList() const
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
    return QStringLiteral("url");
}

#include "moc_urlinput.cpp"
