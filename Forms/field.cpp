/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "field_p.h"

using namespace CutelystForms;

FieldPrivate::FieldPrivate(Field::Type _type, Field *q) :
    FormHtmlElementPrivate(Tag::Input, q), options(q), optgroups(q), type(_type)
{

}

QStringList FieldPrivate::attrList() const
{
    QStringList lst = FormHtmlElementPrivate::attrList();

    if (type == Field::File && !accept.isEmpty()) {
        lst.append(u"accept=\""_qs + accept + QLatin1Char('"'));
    }
    if (autocomplete.isEmpty()) {
        lst.append(u"autocomplete=\""_qs + autocomplete + QLatin1Char('"'));
    }
    if (checked && (type == Field::Radio || type == Field::Checkbox)) {
        lst.append(u"checked"_qs);
    }
    if (disabled) {
        lst.append(u"disabled"_qs);
    }
    if (multiple && (tag == Tag::Select || type == Field::File || Field::Email)) {
        lst.append(u"multiple"_qs);
    }
    if (name.isEmpty()) {
        lst.append(u"name=\""_qs + name + QLatin1Char('"'));
    }
    if (required) {
        lst.append(u"required"_qs);
    }
    if (value.isValid()) {
        lst.append(u"value=\""_qs + value.toString() + QLatin1Char('"'));
    }

    return lst;
}

Field::Field(QObject *parent) :
    FormHtmlElement(* new FieldPrivate(Field::None, this), parent)
{

}

Field::Field(FieldPrivate &dd, QObject *parent) :
    FormHtmlElement(dd, parent)
{

}

QString Field::accept() const noexcept
{
    Q_D(const Field);
    return d->accept;
}

void Field::setAccept(const QString &accept) noexcept
{
    Q_D(Field);
    d->accept = accept;
}

QString Field::autocomplete() const noexcept
{
    Q_D(const Field);
    return d->autocomplete;
}

void Field::setAutocomplete(const QString &autocomplete) noexcept
{
    Q_D(Field);
    d->autocomplete = autocomplete;
}

bool Field::checked() const noexcept
{
    Q_D(const Field);
    return d->checked;
}

void Field::setChecked(bool checked) noexcept
{
    Q_D(Field);
    d->checked = checked;
}

QString Field::description() const noexcept
{
    Q_D(const Field);
    return d->description;
}

void Field::setDescription(const QString &description) noexcept
{
    Q_D(Field);
    d->description = description;
}

bool Field::disabled() const noexcept
{
    Q_D(const Field);
    return d->disabled;
}

void Field::setDisabled(bool disabled) noexcept
{
    Q_D(Field);
    d->disabled = disabled;
}

QString Field::label() const noexcept
{
    Q_D(const Field);
    return d->label;
}

void Field::setLabel(const QString &label) noexcept
{
    Q_D(Field);
    d->label = label;
}

bool Field::multiple() const noexcept
{
    Q_D(const Field);
    return d->multiple;
}

void Field::setMultiple(bool multiple) noexcept
{
    Q_D(Field);
    d->multiple = multiple;
}

QString Field::name() const noexcept
{
    Q_D(const Field);
    return d->name;
}

void Field::setName(const QString &name) noexcept
{
    Q_D(Field);
    d->name = name;
}

bool Field::required() const noexcept
{
    Q_D(const Field);
    return d->required;
}

void Field::setRequired(bool required) noexcept
{
    Q_D(Field);
    d->required = required;
}

CutelystForms::Field::Type Field::type() const noexcept
{
    return None;
}

QString Field::typeString() const noexcept
{
    return {};
}

QVariant Field::value() const noexcept
{
    Q_D(const Field);
    return d->value;
}

void Field::setValue(const QVariant &value) noexcept
{
    Q_D(Field);
    d->value = value;
}

QQmlListProperty<CutelystForms::Option> Field::options()
{
    Q_D(Field);
    return {this, nullptr,
        &FieldPrivate::appendOption,
        &FieldPrivate::optionCount,
        &FieldPrivate::option,
        &FieldPrivate::clearOptions,
        &FieldPrivate::replaceOption,
        &FieldPrivate::removeLastOption
    };
}

void Field::appendOption(Option *option)
{
    Q_D(Field);
    d->options.append(option);
}

QList<Option*>::size_type Field::optionCount() const noexcept
{
    Q_D(const Field);
    return d->options.count();
}

Option* Field::option(QList<Option*>::size_type idx) const
{
    Q_D(const Field);
    return d->options.item(idx);
}

Option* Field::optionById(const QString &id) const
{
    Q_D(const Field);
    return d->options.itemById(id);
}

void Field::clearOptions()
{
    Q_D(Field);
    d->options.clear();
}

void Field::replaceOption(QList<Option*>::size_type idx, Option *o)
{
    Q_D(Field);
    d->options.replace(idx, o);
}

void Field::removeLastOption()
{
    Q_D(Field);
    d->options.removeLast();
}

QList<Option*> Field::optionList() const noexcept
{
    Q_D(const Field);
    return d->options.list();
}

QMap<QString, Option*> Field::optionIdMap() const noexcept
{
    Q_D(const Field);
    return d->options.idMap();
}

QQmlListProperty<CutelystForms::Optgroup> Field::optgroups()
{
    Q_D(Field);
    return {this, nullptr,
        &FieldPrivate::appendOptgroup,
        &FieldPrivate::optgroupCount,
        &FieldPrivate::optgroup,
        &FieldPrivate::clearOptgroups,
        &FieldPrivate::replaceOptgroup,
        &FieldPrivate::removeLastOptgroup
    };
}

void Field::appendOptgroup(Optgroup *optgroup)
{
    Q_D(Field);
    d->optgroups.append(optgroup);
}

QList<Optgroup*>::size_type Field::optgroupCount() const noexcept
{
    Q_D(const Field);
    return d->optgroups.count();
}

Optgroup* Field::optgroup(QList<Optgroup*>::size_type idx) const
{
    Q_D(const Field);
    return d->optgroups.item(idx);
}

Optgroup* Field::optgroupById(const QString &id) const
{
    Q_D(const Field);
    return d->optgroups.itemById(id);
}

void Field::clearOptgroups()
{
    Q_D(Field);
    d->optgroups.clear();
}

void Field::replaceOptgroup(QList<Optgroup*>::size_type idx, Optgroup *o)
{
    Q_D(Field);
    d->optgroups.replace(idx, o);
}

void Field::removeLastOptgroup()
{
    Q_D(Field);
    d->optgroups.removeLast();
}

QList<Optgroup*> Field::optgroupList() const noexcept
{
    Q_D(const Field);
    return d->optgroups.list();
}

QMap<QString, Optgroup*> Field::optgroupIdMap() const noexcept
{
    Q_D(const Field);
    return d->optgroups.idMap();
}

#include "moc_field.cpp"
