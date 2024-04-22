/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "option_p.h"

using namespace CutelystForms;

OptionPrivate::OptionPrivate(Option *q)
    : SelectContentPrivate(q)
{
    tag = Tag::Option;
}

QStringList OptionPrivate::attrList() const
{
    QStringList lst = SelectContentPrivate::attrList();

    if (!value.isNull()) {
        lst.append(u"value=\""_qs + value + QLatin1Char('"'));
    }

    if (selected) {
        lst.append(u"selected"_qs);
    }

    return lst;
}

Option::Option(QObject *parent)
    : SelectContent(*new OptionPrivate(this), parent)
{
}

Option::Option(OptionPrivate &dd, QObject *parent)
    : SelectContent(dd, parent)
{
}

bool Option::isSelected() const noexcept
{
    Q_D(const Option);
    return d->selected;
}

void Option::setSelected(bool selected) noexcept
{
    Q_D(Option);
    d->selected = selected;
}

QString Option::text() const noexcept
{
    Q_D(const Option);
    return d->text;
}

void Option::setText(const QString &text) noexcept
{
    Q_D(Option);
    d->text = text;
}

QString Option::value() const noexcept
{
    Q_D(const Option);
    return d->value;
}

void Option::setValue(const QString &value) noexcept
{
    Q_D(Option);
    d->value = value;
}

QString Option::tagName() const noexcept
{
    return QStringLiteral("option");
}

#include "moc_option.cpp"
