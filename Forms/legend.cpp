/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "legend_p.h"

using namespace CutelystForms;

LegendPrivate::LegendPrivate(Legend *q)
    : FormHtmlElementPrivate(Tag::Legend, q)
{
}

Legend::Legend(QObject *parent)
    : FormHtmlElement(*new LegendPrivate(this), parent)
{
}

Legend::Legend(LegendPrivate &dd, QObject *parent)
    : FormHtmlElement(dd, parent)
{
}

QString Legend::text() const noexcept
{
    Q_D(const Legend);
    return d->text;
}

void Legend::setText(const QString &text) noexcept
{
    Q_D(Legend);
    d->text = text;
}

QString Legend::tagName() const noexcept
{
    return QStringLiteral("legend");
}

#include "moc_legend.cpp"
