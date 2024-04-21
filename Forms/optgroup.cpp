/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "optgroup_p.h"

using namespace CutelystForms;

OptgroupPrivate::OptgroupPrivate(Optgroup *q)
    : SelectContentPrivate(q)
    , options(q)
{
    tag = Tag::Optgroup;
}

Optgroup::Optgroup(QObject *parent)
    : SelectContent(*new OptgroupPrivate(this), parent)
{
}

Optgroup::Optgroup(OptgroupPrivate &dd, QObject *parent)
    : SelectContent(dd, parent)
{
}

QString Optgroup::tagName() const noexcept
{
    return QStringLiteral("optgroup");
}

QQmlListProperty<CutelystForms::Option> Optgroup::options()
{
    Q_D(Optgroup);
    return {this,
            nullptr,
            &OptgroupPrivate::appendOption,
            &OptgroupPrivate::optionCount,
            &OptgroupPrivate::option,
            &OptgroupPrivate::clearOptions,
            &OptgroupPrivate::replaceOption,
            &OptgroupPrivate::removeLastOption};
}

void Optgroup::appendOption(Option *option)
{
    Q_D(Optgroup);
    d->options.append(option);
}

QList<Option *>::size_type Optgroup::optionCount() const noexcept
{
    Q_D(const Optgroup);
    return d->options.count();
}

Option *Optgroup::option(QList<Option *>::size_type idx) const
{
    Q_D(const Optgroup);
    return d->options.item(idx);
}

Option *Optgroup::optionById(const QString &id) const
{
    Q_D(const Optgroup);
    return d->options.itemById(id);
}

void Optgroup::replaceOption(QList<Option *>::size_type idx, Option *o)
{
    Q_D(Optgroup);
    d->options.replace(idx, o);
}

void Optgroup::removeLastOption()
{
    Q_D(Optgroup);
    d->options.removeLast();
}

void Optgroup::clearOptions()
{
    Q_D(Optgroup);
    d->options.clear();
}

QList<Option *> Optgroup::optionList() const noexcept
{
    Q_D(const Optgroup);
    return d->options.list();
}

QMap<QString, Option *> Optgroup::optionIdMap() const noexcept
{
    Q_D(const Optgroup);
    return d->options.idMap();
}

#include "moc_optgroup.cpp"
