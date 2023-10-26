/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "form_p.h"
#include "logging_p.h"

using namespace CutelystForms;

FormPrivate::FormPrivate(Form *q) :
    FormHtmlElementPrivate(q)
{

}

Form::Form(QObject *parent) :
    FormHtmlElement(* new FormPrivate(this), parent)
{

}

Form::Form(FormPrivate &dd, QObject *parent) :
    FormHtmlElement(dd, parent)
{

}

QUrl Form::action() const noexcept
{
    Q_D(const Form);
    return d->action;
}

void Form::setAction(const QUrl &action) noexcept
{
    Q_D(Form);
    d->action = action;
}

QStringList Form::acceptCharset() const noexcept
{
    Q_D(const Form);
    return d->acceptCharset;
}

void Form::setAcceptCharset(const QStringList &acceptCharset) noexcept
{
    Q_D(Form);
    d->acceptCharset = acceptCharset;
}

bool Form::autocomplete() const noexcept
{
    Q_D(const Form);
    return d->autocomplete;
}

void Form::setAutocomplete(bool autocomplete) noexcept
{
    Q_D(Form);
    d->autocomplete = autocomplete;
}

CutelystForms::Form::EncType Form::enctype() const noexcept
{
    Q_D(const Form);
    return d->enctype;
}

void Form::setEnctype(CutelystForms::Form::EncType enctype) noexcept
{
    Q_D(Form);
    d->enctype = enctype;
}

CutelystForms::Form::Method Form::method() const noexcept
{
    Q_D(const Form);
    return d->method;
}

void Form::setMethod(CutelystForms::Form::Method method) noexcept
{
    Q_D(Form);
    d->method = method;
}

QString Form::name() const noexcept
{
    Q_D(const Form);
    return d->name;
}

void Form::setName(const QString &name) noexcept
{
    Q_D(Form);
    d->name = name;
}

bool Form::novalidate() const noexcept
{
    Q_D(const Form);
    return d->novalidate;
}

void Form::setNovalidate(bool novalidate) noexcept
{
    Q_D(Form);
    d->novalidate = novalidate;
}

CutelystForms::Form::Target Form::target() const noexcept
{
    Q_D(const Form);
    return d->target;
}

void Form::setTarget(CutelystForms::Form::Target target) noexcept
{
    Q_D(Form);
    d->target = target;
}

QString Form::label() const noexcept
{
    Q_D(const Form);
    return d->label;
}

void Form::setLabel(const QString &label) noexcept
{
    Q_D(Form);
    d->label = label;
}

QString Form::description() const noexcept
{
    Q_D(const Form);
    return d->description;
}

void Form::setDescription(const QString &description) noexcept
{
    Q_D(Form);
    d->description = description;
}

CutelystForms::Form::Type Form::type() const noexcept
{
    Q_D(const Form);
    return d->type;
}

void Form::setType(CutelystForms::Form::Type type) noexcept
{
    Q_D(Form);
    d->type = type;
}

QString Form::tagName() const noexcept
{
    return QStringLiteral("form");
}

QQmlListProperty<CutelystForms::Field> Form::fields()
{
    Q_D(Form);
    return {this, &d->fields,
                &FormPrivate::appendField,
                &FormPrivate::fieldCount,
                &FormPrivate::field,
                &FormPrivate::clearFields,
                &FormPrivate::replaceField,
                &FormPrivate::removeLastField
    };
}

void Form::appendField(Field *field)
{
    Q_D(Form);
    field->setParent(this);
    d->fields.push_back(field);
    if (!field->name().isEmpty()) {
        if (d->fieldNameMap.contains(field->name())) {
            qCWarning(C_FORMS) << *this << "already contains a field with name" << field->name() << "- appending it anyway. Note that this will overwrite the field with the same name in the fieldNameMap!";
        }
        d->fieldNameMap.insert(field->name(), field);
    }
    if (!field->htmlId().isEmpty()) {
        if (d->fieldIdMap.contains(field->htmlId())) {
            qCWarning(C_FORMS) << *this << "already contains a field with id" << field->htmlId() << "- appending it anyway. Note that this will overwrite the field with the same id in the fieldIdMap!";
        }
    }
}

QList<Field*>::size_type Form::fieldCount() const noexcept
{
    Q_D(const Form);
    return d->fields.size();
}

Field* Form::field(QList<Field*>::size_type idx) const
{
    Q_D(const Form);
    if (idx < d->fields.size()) {
        return d->fields.at(idx);
    } else {
        return nullptr;
    }
}

Field* Form::fieldByName(const QString &name) const
{
    Q_D(const Form);
    return d->fieldNameMap.value(name, nullptr);
}

Field* Form::fieldById(const QString &id) const
{
    Q_D(const Form);
    return d->fieldIdMap.value(id, nullptr);
}

void Form::clearFields()
{
    Q_D(Form);
    d->fields.clear();
    d->fieldNameMap.clear();
    d->fieldIdMap.clear();
}

void Form::replaceField(QList<Field*>::size_type idx, Field *f)
{
    Q_D(Form);
    Field *current = this->field(idx);
    if (current) {
        if (!current->name().isEmpty()) {
            d->fieldNameMap.remove(current->name());
        }
        if (!current->htmlId().isEmpty()) {
            d->fieldIdMap.remove(current->htmlId());
        }
    }
    f->setParent(this);
    d->fields[idx] = f;
    if (!f->name().isEmpty()) {
        if (d->fieldNameMap.contains(f->name())) {
            qCWarning(C_FORMS) << *this << "already contains a field with name" << f->name() << "- replacing it anyway. Note that this will overwrite the field with the same name in the fieldNameMap!";
        }
        d->fieldNameMap.insert(f->name(), f);
    }
    if (!f->htmlId().isEmpty()) {
        if (d->fieldIdMap.contains(f->htmlId())) {
            qCWarning(C_FORMS) << *this << "already contains a field with id" << f->htmlId() << "- replacing it anyway. Note that this will overwrite the field with the same id in the fieldIdMap!";
        }
    }
}

void Form::removeLastField()
{
    Q_D(Form);
    if (d->fields.empty()) {
        return;
    }
    Field *last = d->fields.takeLast();
    if (!last->name().isEmpty()) {
        d->fieldNameMap.remove(last->name());
    }
    if (!last->htmlId().isEmpty()) {
        d->fieldIdMap.remove(last->htmlId());
    }
}

QList<Field*> Form::fieldList() const noexcept
{
    Q_D(const Form);
    return d->fields;
}

QMap<QString, Field*> Form::fieldNameMap() const noexcept
{
    Q_D(const Form);
    return d->fieldNameMap;
}

QMap<QString, Field*> Form::fieldIdMap() const noexcept
{
    Q_D(const Form);
    return d->fieldIdMap;
}

QQmlListProperty<CutelystForms::Fieldset> Form::fieldsets()
{
    Q_D(Form);
    return {this, &d->fieldsets};
}

void Form::appendFieldset(Fieldset *fieldset)
{
    Q_D(Form);
    d->fieldsets.push_back(fieldset);
}

QList<Fieldset*>::size_type Form::fieldsetCount() const noexcept
{
    Q_D(const Form);
    return d->fieldsets.size();
}

Fieldset* Form::fieldset(QList<Fieldset*>::size_type idx) const
{
    Q_D(const Form);
    if (idx < d->fieldsets.size()) {
        return d->fieldsets.at(idx);
    } else {
        return nullptr;
    }
}

void Form::clearFieldsets()
{
    Q_D(Form);
    qDeleteAll(d->fieldsets);
    d->fieldsets.clear();
}

QList<Fieldset*> Form::fieldsetList() const noexcept
{
    Q_D(const Form);
    return d->fieldsets;
}

QQmlListProperty<CutelystForms::Button> Form::buttons()
{
    Q_D(Form);
    return {this, &d->buttons};
}

void Form::appendButton(Button *button)
{
    Q_D(Form);
    d->buttons.push_back(button);
}

QList<Button*>::size_type Form::buttonCount() const noexcept
{
    Q_D(const Form);
    return d->buttons.size();
}

Button* Form::button(QList<Button*>::size_type idx) const
{
    Q_D(const Form);
    if (idx < d->buttons.size()) {
        return d->buttons.at(idx);
    } else {
        return nullptr;
    }
}

void Form::clearButtons()
{
    Q_D(Form);
    qDeleteAll(d->buttons);
    d->buttons.clear();
}

QList<Button*> Form::buttonList() const noexcept
{
    Q_D(const Form);
    return d->buttons;
}

void FormPrivate::appendField(QQmlListProperty<Field>* list, Field* field)
{
    auto form = qobject_cast<Form*>(list->object);
    if (form) {
        form->appendField(field);
    }
}

QList<Field*>::size_type FormPrivate::fieldCount(QQmlListProperty<Field>* list)
{
    auto form = qobject_cast<Form*>(list->object);
    if (form) {
        return form->fieldCount();
    } else {
        return 0;
    }
}

Field* FormPrivate::field(QQmlListProperty<Field>* list, QList<Field*>::size_type idx)
{
    auto form = qobject_cast<Form*>(list->object);
    if (form) {
        return form->field(idx);
    } else {
        return nullptr;
    }
}

void FormPrivate::clearFields(QQmlListProperty<Field>* list)
{
    auto form = qobject_cast<Form*>(list->object);
    if (form) {
        form->clearFields();
    }
}

void FormPrivate::replaceField(QQmlListProperty<Field>* list, QList<Field*>::size_type idx, Field* field)
{
    auto form = qobject_cast<Form*>(list->object);
    if (form) {
        form->replaceField(idx, field);
    }
}

void FormPrivate::removeLastField(QQmlListProperty<Field> *list)
{
    auto form = qobject_cast<Form*>(list->object);
    if (form) {
        form->removeLastField();
    }
}

QDebug operator<<(QDebug dbg, const CutelystForms::Form &form)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "CutelystForms::Form(";
    dbg << "ID: " << form.htmlId();
    dbg << ", Name: " << form.name();
    dbg << ')';
    return dbg.maybeSpace();
}

#include "moc_form.cpp"
