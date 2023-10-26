/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "select_p.h"

using namespace CutelystForms;

SelectPrivate::SelectPrivate(Select *q) :
    FieldPrivate(q)
{
    type = Field::Select;
}

Select::Select(QObject *parent) :
    Field(* new SelectPrivate(this), parent)
{

}

Select::Select(SelectPrivate &dd, QObject *parent) :
    Field(dd, parent)
{

}

bool Select::multiple() const noexcept
{
    Q_D(const Select);
    return d->multiple;
}

void Select::setMultiple(bool multiple) noexcept
{
    Q_D(Select);
    d->multiple = multiple;
}

int Select::size() const noexcept
{
    Q_D(const Select);
    return d->size;
}

void Select::setSize(int size) noexcept
{
    Q_D(Select);
    d->size = size;
}

QQmlListProperty<CutelystForms::SelectContent> Select::options()
{
    Q_D(Select);
    return {this, &d->content};
}

void Select::appendContent(SelectContent *content)
{
    Q_D(Select);
    d->content.push_back(content);
}

QList<SelectContent*>::size_type Select::contentCount() const
{
    Q_D(const Select);
    return static_cast<int>(d->content.size());
}

SelectContent* Select::content(QList<SelectContent*>::size_type idx) const
{
    Q_D(const Select);
    if (idx < d->content.size()) {
        return d->content.at(idx);
    } else {
        return nullptr;
    }
}

void Select::clearContent()
{
    Q_D(Select);
    qDeleteAll(d->content);
    d->content.clear();
}

QList<SelectContent*> Select::contentList() const noexcept
{
    Q_D(const Select);
    return d->content;
}

#include "moc_select.cpp"
