/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "select_p.h"

using namespace CutelystForms;

SelectPrivate::SelectPrivate(Select *q) :
    FieldPrivate(q)
{

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

QQmlListProperty<CutelystForms::Option> Select::options()
{
    Q_D(Select);
    return {this, &d->options};
}

void Select::appendOption(Option *option)
{
    Q_D(Select);
    d->options.push_back(option);
}

QList<Option*>::size_type Select::optionCount() const noexcept
{
    Q_D(const Select);
    return d->options.size();
}

Option* Select::option(QList<Option*>::size_type idx) const
{
    Q_D(const Select);
    if (idx < d->options.size()) {
        return d->options.at(idx);
    } else {
        return nullptr;
    }
}

void Select::clearOptions()
{
    Q_D(Select);
    qDeleteAll(d->options);
    d->options.clear();
}

QList<Option*> Select::optionList() const noexcept
{
    Q_D(const Select);
    return d->options;
}

QQmlListProperty<CutelystForms::Optgroup> Select::optgroups()
{
    Q_D(Select);
    return {this, &d->optgroups};
}

void Select::appendOptgroup(Optgroup *optgroup)
{
    Q_D(Select);
    d->optgroups.push_back(optgroup);
}

QList<Optgroup*>::size_type Select::optgroupCount() const noexcept
{
    Q_D(const Select);
    return d->optgroups.size();
}

Optgroup* Select::optgroup(QList<Optgroup*>::size_type idx) const
{
    Q_D(const Select);
    if (idx >= 0 && idx < d->optgroups.size()) {
        return d->optgroups.at(idx);
    } else {
        return nullptr;
    }
}

void Select::clearOptgroups()
{
    Q_D(Select);
    qDeleteAll(d->optgroups);
    d->optgroups.clear();
}

QList<Optgroup*> Select::optgroupList() const noexcept
{
    Q_D(const Select);
    return d->optgroups;
}

#include "moc_select.cpp"
