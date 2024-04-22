/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "field_p.h"

#include <QDate>
#include <QDateTime>
#include <QTime>

using namespace CutelystForms;

FieldPrivate::FieldPrivate(Field::Type _type, Field *q)
    : FormHtmlElementPrivate(Tag::Input, q)
    , options(q)
    , optgroups(q)
    , type(_type)
{
}

QStringList FieldPrivate::attrList() const
{
    QStringList lst = FormHtmlElementPrivate::attrList();

    if (!name.isNull()) {
        lst.append(u"name=\""_qs + name + QLatin1Char('"'));
    }

    if (!value.isNull()) {
        lst.append(u"value=\""_qs + getValueString() + QLatin1Char('"'));
    }

    if (!autocomplete.isEmpty() &&
        !(type == Field::Checkbox || type == Field::Radio || type == Field::File)) {
        lst.append(u"autocomplete=\""_qs + autocomplete + QLatin1Char('"'));
    }

    if (disabled) {
        lst.append(u"disabled"_qs);
    }

    if (required && !(type == Field::Hidden || type == Field::Color || type == Field::Range)) {
        lst.append(u"required"_qs);
    }

    return lst;
}

QString FieldPrivate::getValueString() const
{
    return value.toString();
}

Field::Field(QObject *parent)
    : FormHtmlElement(*new FieldPrivate(Field::None, this), parent)
{
}

Field::Field(FieldPrivate &dd, QObject *parent)
    : FormHtmlElement(dd, parent)
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

QStringList Field::errors() const noexcept
{
    Q_D(const Field);
    return d->errors;
}

void Field::setErrors(const QStringList &errors)
{
    Q_D(Field);
    d->errors = errors;
}

void Field::addErrors(const QStringList &errors)
{
    Q_D(Field);
    d->errors.append(errors);
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

QString Field::list() const noexcept
{
    Q_D(const Field);
    return d->list;
}

void Field::setList(const QString &list) noexcept
{
    Q_D(Field);
    d->list = list;
}

QVariant Field::max() const noexcept
{
    Q_D(const Field);
    return d->max;
}

void Field::setMax(const QVariant &max) noexcept
{
    Q_D(Field);
    d->max = max;
}

int Field::maxlength() const noexcept
{
    Q_D(const Field);
    return d->maxlength;
}

void Field::setMaxlength(int maxlength) noexcept
{
    Q_D(Field);
    d->maxlength = maxlength;
}

QVariant Field::min() const noexcept
{
    Q_D(const Field);
    return d->min;
}

void Field::setMin(const QVariant &min) noexcept
{
    Q_D(Field);
    d->min = min;
}

int Field::minlength() const noexcept
{
    Q_D(const Field);
    return d->minlength;
}

void Field::setMinlength(int minlength) noexcept
{
    Q_D(Field);
    d->minlength = minlength;
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

QString Field::placeholder() const noexcept
{
    Q_D(const Field);
    return d->placeholder;
}

void Field::setPlaceholder(const QString &placeholder) noexcept
{
    Q_D(Field);
    d->placeholder = placeholder;
}

QString Field::pattern() const noexcept
{
    Q_D(const Field);
    return d->pattern;
}

void Field::setPattern(const QString &pattern) noexcept
{
    Q_D(Field);
    d->pattern = pattern;
}

bool Field::readonly() const noexcept
{
    Q_D(const Field);
    return d->readonly;
}

void Field::setReadonly(bool readonly) noexcept
{
    Q_D(Field);
    d->readonly = readonly;
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

QVariant Field::step() const noexcept
{
    Q_D(const Field);
    return d->step;
}

void Field::setStep(const QVariant &step) noexcept
{
    Q_D(Field);
    d->step = step;
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

QString Field::tagName() const noexcept
{
    return u"input"_qs;
}

QQmlListProperty<CutelystForms::Option> Field::options()
{
    Q_D(Field);
    return {this,
            nullptr,
            &FieldPrivate::appendOption,
            &FieldPrivate::optionCount,
            &FieldPrivate::option,
            &FieldPrivate::clearOptions,
            &FieldPrivate::replaceOption,
            &FieldPrivate::removeLastOption};
}

void Field::appendOption(Option *option)
{
    Q_D(Field);
    d->options.append(option);
}

QList<Option *>::size_type Field::optionCount() const noexcept
{
    Q_D(const Field);
    return d->options.count();
}

Option *Field::option(QList<Option *>::size_type idx) const
{
    Q_D(const Field);
    return d->options.item(idx);
}

Option *Field::optionById(const QString &id) const
{
    Q_D(const Field);
    return d->options.itemById(id);
}

void Field::clearOptions()
{
    Q_D(Field);
    d->options.clear();
}

void Field::replaceOption(QList<Option *>::size_type idx, Option *o)
{
    Q_D(Field);
    d->options.replace(idx, o);
}

void Field::removeLastOption()
{
    Q_D(Field);
    d->options.removeLast();
}

QList<Option *> Field::optionList() const noexcept
{
    Q_D(const Field);
    return d->options.list();
}

QMap<QString, Option *> Field::optionIdMap() const noexcept
{
    Q_D(const Field);
    return d->options.idMap();
}

QQmlListProperty<CutelystForms::Optgroup> Field::optgroups()
{
    Q_D(Field);
    return {this,
            nullptr,
            &FieldPrivate::appendOptgroup,
            &FieldPrivate::optgroupCount,
            &FieldPrivate::optgroup,
            &FieldPrivate::clearOptgroups,
            &FieldPrivate::replaceOptgroup,
            &FieldPrivate::removeLastOptgroup};
}

void Field::appendOptgroup(Optgroup *optgroup)
{
    Q_D(Field);
    d->optgroups.append(optgroup);
}

QList<Optgroup *>::size_type Field::optgroupCount() const noexcept
{
    Q_D(const Field);
    return d->optgroups.count();
}

Optgroup *Field::optgroup(QList<Optgroup *>::size_type idx) const
{
    Q_D(const Field);
    return d->optgroups.item(idx);
}

Optgroup *Field::optgroupById(const QString &id) const
{
    Q_D(const Field);
    return d->optgroups.itemById(id);
}

void Field::clearOptgroups()
{
    Q_D(Field);
    d->optgroups.clear();
}

void Field::replaceOptgroup(QList<Optgroup *>::size_type idx, Optgroup *o)
{
    Q_D(Field);
    d->optgroups.replace(idx, o);
}

void Field::removeLastOptgroup()
{
    Q_D(Field);
    d->optgroups.removeLast();
}

QList<Optgroup *> Field::optgroupList() const noexcept
{
    Q_D(const Field);
    return d->optgroups.list();
}

QMap<QString, Optgroup *> Field::optgroupIdMap() const noexcept
{
    Q_D(const Field);
    return d->optgroups.idMap();
}

#include "moc_field.cpp"
