/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "selectcontent_p.h"

using namespace CutelystForms;

SelectContentPrivate::SelectContentPrivate(SelectContent *q)
    : FormHtmlElementPrivate(Tag::None, q)
{
}

QStringList SelectContentPrivate::attrList() const
{
    QStringList lst = FormHtmlElementPrivate::attrList();

    if (disabled) {
        lst.append(u"disabled"_qs);
    }

    if (!label.isEmpty()) {
        lst.append(u"label=\""_qs + label + QLatin1Char('"'));
    }

    return lst;
}

SelectContent::SelectContent(QObject *parent)
    : FormHtmlElement(*new SelectContentPrivate(this), parent)
{
}

SelectContent::SelectContent(SelectContentPrivate &dd, QObject *parent)
    : FormHtmlElement(dd, parent)
{
}

bool SelectContent::isDisabled() const noexcept
{
    Q_D(const SelectContent);
    return d->disabled;
}

void SelectContent::setDisabled(bool disabled) noexcept
{
    Q_D(SelectContent);
    d->disabled = disabled;
}

QString SelectContent::label() const noexcept
{
    Q_D(const SelectContent);
    return d->label;
}

void SelectContent::setLabel(const QString &label) noexcept
{
    Q_D(SelectContent);
    d->label = label;
}

#include "moc_selectcontent.cpp"
