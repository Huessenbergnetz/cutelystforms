/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "option_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

OptionPrivate::OptionPrivate(Option *q)
    : SelectContentPrivate(q)
{
    tag = Tag::Option;
}

OptionPrivate::OptionPrivate(const QString &_text, const QString &_value, bool _selected, Option *q)
    : SelectContentPrivate(q)
    , text(_text)
    , value(_value)
    , selected(_selected)
{
}

QStringList OptionPrivate::attrList() const
{
    QStringList lst = SelectContentPrivate::attrList();

    if (!value.isNull()) {
        lst.append(u"value=\""_s + value + '"'_L1);
    }

    if (selected) {
        lst.append(u"selected"_s);
    }

    return lst;
}

Option::Option(QObject *parent)
    : SelectContent(*new OptionPrivate(this), parent)
{
}

Option::Option(const QString &text, const QString &value, bool selected, QObject *parent)
    : SelectContent(*new OptionPrivate(text, value, selected, this), parent)
{
}

Option::Option(const QString &textAndValue, bool selected, QObject *parent)
    : SelectContent(*new OptionPrivate(textAndValue, textAndValue, selected, this), parent)
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
    return u"option"_s;
}

#include "moc_option.cpp"
