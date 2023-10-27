/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "select_p.h"

using namespace CutelystForms;

SelectPrivate::SelectPrivate(Select *q) :
    FieldPrivate(q), options(q), optgroups(q)
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

QString Select::tagName() const noexcept
{
    return QStringLiteral("select");
}

QQmlListProperty<CutelystForms::Option> Select::options()
{
    Q_D(Select);
    return {this, nullptr,
        &SelectPrivate::appendOption,
        &SelectPrivate::optionCount,
        &SelectPrivate::option,
        &SelectPrivate::clearOptions,
        &SelectPrivate::replaceOption,
        &SelectPrivate::removeLastOption
    };
}

void Select::appendOption(Option *option)
{
    Q_D(Select);
    d->options.append(option);
}

QList<Option*>::size_type Select::optionCount() const noexcept
{
    Q_D(const Select);
    return d->options.count();
}

Option* Select::option(QList<Option*>::size_type idx) const
{
    Q_D(const Select);
    return d->options.item(idx);
}

Option* Select::optionById(const QString &id) const
{
    Q_D(const Select);
    return d->options.itemById(id);
}

void Select::clearOptions()
{
    Q_D(Select);
    d->options.clear();
}

void Select::replaceOption(QList<Option*>::size_type idx, Option *o)
{
    Q_D(Select);
    d->options.replace(idx, o);
}

void Select::removeLastOption()
{
    Q_D(Select);
    d->options.removeLast();
}

QList<Option*> Select::optionList() const noexcept
{
    Q_D(const Select);
    return d->options.list();
}

QMap<QString, Option*> Select::optionIdMap() const noexcept
{
    Q_D(const Select);
    return d->options.idMap();
}

QQmlListProperty<CutelystForms::Optgroup> Select::optgroups()
{
    Q_D(Select);
    return {this, nullptr,
        &SelectPrivate::appendOptgroup,
        &SelectPrivate::optgroupCount,
        &SelectPrivate::optgroup,
        &SelectPrivate::clearOptgroups,
        &SelectPrivate::replaceOptgroup,
        &SelectPrivate::removeLastOptgroup
    };
}

void Select::appendOptgroup(Optgroup *optgroup)
{
    Q_D(Select);
    d->optgroups.append(optgroup);
}

QList<Optgroup*>::size_type Select::optgroupCount() const noexcept
{
    Q_D(const Select);
    return d->optgroups.count();
}

Optgroup* Select::optgroup(QList<Optgroup*>::size_type idx) const
{
    Q_D(const Select);
    return d->optgroups.item(idx);
}

Optgroup* Select::optgroupById(const QString &id) const
{
    Q_D(const Select);
    return d->optgroups.itemById(id);
}

void Select::clearOptgroups()
{
    Q_D(Select);
    d->optgroups.clear();
}

void Select::replaceOptgroup(QList<Optgroup*>::size_type idx, Optgroup *o)
{
    Q_D(Select);
    d->optgroups.replace(idx, o);
}

void Select::removeLastOptgroup()
{
    Q_D(Select);
    d->optgroups.removeLast();
}

QList<Optgroup*> Select::optgroupList() const noexcept
{
    Q_D(const Select);
    return d->optgroups.list();
}

QMap<QString, Optgroup*> Select::optgroupIdMap() const noexcept
{
    Q_D(const Select);
    return d->optgroups.idMap();
}

#include "moc_select.cpp"
