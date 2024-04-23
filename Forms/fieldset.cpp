/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fieldset_p.h"

using namespace CutelystForms;

FieldsetPrivate::FieldsetPrivate(Fieldset *q)
    : FormHtmlElementPrivate(Tag::Fieldset, q)
    , fields(q)
{
}

QStringList FieldsetPrivate::attrList() const
{
    QStringList lst = FormHtmlElementPrivate::attrList();

    if (disabled) {
        lst.append(u"disabled"_qs);
    }
    if (!form.isEmpty()) {
        lst.append(u"form=\""_qs + form + QLatin1Char('"'));
    }
    if (!name.isEmpty()) {
        lst.append(u"name=\""_qs + name + QLatin1Char('"'));
    }

    return lst;
}

Fieldset::Fieldset(QObject *parent)
    : FormHtmlElement(*new FieldsetPrivate(this), parent)
{
}

Fieldset::Fieldset(FieldsetPrivate &dd, QObject *parent)
    : FormHtmlElement(dd, parent)
{
}

bool Fieldset::isDisabled() const noexcept
{
    Q_D(const Fieldset);
    return d->disabled;
}

void Fieldset::setDisabled(bool disabled) noexcept
{
    Q_D(Fieldset);
    d->disabled = disabled;
}

QString Fieldset::form() const noexcept
{
    Q_D(const Fieldset);
    return d->form;
}

void Fieldset::setForm(const QString &form) noexcept
{
    Q_D(Fieldset);
    d->form = form;
}

QString Fieldset::name() const noexcept
{
    Q_D(const Fieldset);
    return d->name;
}

void Fieldset::setName(const QString &name) noexcept
{
    Q_D(Fieldset);
    d->name = name;
}

QString Fieldset::description() const noexcept
{
    Q_D(const Fieldset);
    return d->description;
}

void Fieldset::setDescription(const QString &description) noexcept
{
    Q_D(Fieldset);
    d->description = description;
}

QString Fieldset::legend() const noexcept
{
    Q_D(const Fieldset);
    return d->legend;
}

void Fieldset::setLegend(const QString &legend) noexcept
{
    Q_D(Fieldset);
    d->legend = legend;
}

QString Fieldset::tagName() const noexcept
{
    return QStringLiteral("fieldset");
}

QQmlListProperty<CutelystForms::Field> Fieldset::fields()
{
    Q_D(Fieldset);
    return {this,
            nullptr,
            &FieldsetPrivate::appendField,
            &FieldsetPrivate::fieldCount,
            &FieldsetPrivate::field,
            &FieldsetPrivate::clearFields,
            &FieldsetPrivate::replaceField,
            &FieldsetPrivate::removeLastField};
}

void Fieldset::appendField(Field *field)
{
    Q_D(Fieldset);
    d->fields.append(field);
}

QList<Field *>::size_type Fieldset::fieldCount() const noexcept
{
    Q_D(const Fieldset);
    return d->fields.count();
}

Field *Fieldset::field(QList<Field *>::size_type idx) const
{
    Q_D(const Fieldset);
    return d->fields.item(idx);
}

Field *Fieldset::fieldByName(const QString &name) const
{
    Q_D(const Fieldset);
    return d->fields.itemByName(name);
}

Field *Fieldset::fieldById(const QString &id) const
{
    Q_D(const Fieldset);
    return d->fields.itemById(id);
}

void Fieldset::clearFields()
{
    Q_D(Fieldset);
    d->fields.clear();
}

void Fieldset::replaceField(QList<Field *>::size_type idx, Field *f)
{
    Q_D(Fieldset);
    d->fields.replace(idx, f);
}

void Fieldset::removeLastField()
{
    Q_D(Fieldset);
    d->fields.removeLast();
}

QList<Field *> Fieldset::fieldList() const noexcept
{
    Q_D(const Fieldset);
    return d->fields.list();
}

QMap<QString, Field *> Fieldset::fieldNameMap() const noexcept
{
    Q_D(const Fieldset);
    return d->fields.nameMap();
}

QMap<QString, Field *> Fieldset::fieldIdMap() const noexcept
{
    Q_D(const Fieldset);
    return d->fields.idMap();
}

#include "moc_fieldset.cpp"
