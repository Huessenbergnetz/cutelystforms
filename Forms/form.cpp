/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "form_p.h"

using namespace CutelystForms;

FormPrivate::FormPrivate(Form *q) :
    FormHtmlElementPrivate{Tag::Form, q}, fields{q}, fieldsets{q}, buttons{q}
{

}

QStringList FormPrivate::attrList() const
{
    QStringList lst = FormHtmlElementPrivate::attrList();

    if (!acceptCharset.empty()) {
        lst.append(u"accept-charset=\""_qs + acceptCharset.join(QLatin1Char(',')) + QLatin1Char('"'));
    }
    if (action.isValid()) {
        lst.append(u"action=\""_qs + action.toString(QUrl::FullyEncoded) + QLatin1Char('"'));
    }
    lst.append(u"autocomplete=\""_qs + (autocomplete ? u"on"_qs : u"off"_qs) + QLatin1Char('"'));
    if (enctype != Form::WwwFormUrlEncoded) {
        lst.append(u"enctype=\""_qs + enctypeString() + QLatin1Char('"'));
    }
    if (method != Form::Get) {
        lst.append(u"method=\""_qs + methodString() + QLatin1Char('"'));
    }
    if (!name.isEmpty()) {
        lst.append(u"name=\""_qs + name + QLatin1Char('"'));
    }
    if (novalidate) {
        lst.append(u"novalidate"_qs);
    }
    if (target != Form::Self) {
        lst.append(u"target=\""_qs + targetString() + QLatin1Char('"'));
    }

    return lst;
}

QString FormPrivate::enctypeString() const
{
    switch(enctype) {
    case Form::WwwFormUrlEncoded:
        return QStringLiteral("application/x-www-form-urlencoded");
    case Form::MultipartFormData:
        return QStringLiteral("multipart/form-data");
    case Form::TextPlain:
        return QStringLiteral("text/plain");
    }

    Q_UNREACHABLE();
    return {};
}

QString FormPrivate::methodString() const
{
    switch(method) {
    case Form::Get:
        return QStringLiteral("get");
    case Form::Post:
        return QStringLiteral("post");
    }

    Q_UNREACHABLE();
    return {};
}

QString FormPrivate::targetString() const
{
    switch(target) {
    case Form::Self:
        return QStringLiteral("_self");
    case Form::Blank:
        return QStringLiteral("_blank");
    case Form::Parent:
        return QStringLiteral("_parent");
    case Form::Top:
        return QStringLiteral("_top");
    }

    Q_UNREACHABLE();
    return {};
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

void Form::setAcceptCharset(const QStringList &acceptCharset)
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

QString Form::enctypeString() const noexcept
{
    Q_D(const Form);
    return d->enctypeString();
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

QString Form::methodString() const noexcept
{
    Q_D(const Form);
    return d->methodString();
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

void Form::setErrors(const QHash<QString, QStringList> &errors)
{
    Q_D(Form);

    const auto fieldsets = d->fieldsets.list();
    for (auto e = errors.cbegin(), end = errors.cend(); e != end; e++) {
        const auto field = d->fields.itemByName(e.key());
        if (field) {
            field->addErrors(e.value());
        }
        for (auto fs : fieldsets) {
            const auto fsfield = fs->fieldByName(e.key()) ;
            if (fsfield) {
                fsfield->addErrors(e.value());
            }
        }
    }
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

QString Form::targetString() const noexcept
{
    Q_D(const Form);
    return d->targetString();
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

QString Form::tagName() const noexcept
{
    return QStringLiteral("form");
}

QQmlListProperty<CutelystForms::Field> Form::fields()
{
    Q_D(Form);
    return {this, nullptr,
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
    d->fields.append(field);
}

QList<Field*>::size_type Form::fieldCount() const noexcept
{
    Q_D(const Form);
    return d->fields.count();
}

Field* Form::field(QList<Field*>::size_type idx) const
{
    Q_D(const Form);
    return d->fields.item(idx);
}

Field* Form::fieldByName(const QString &name) const
{
    Q_D(const Form);
    return d->fields.itemByName(name);
}

Field* Form::fieldById(const QString &id) const
{
    Q_D(const Form);
    return d->fields.itemById(id);
}

void Form::clearFields()
{
    Q_D(Form);
    d->fields.clear();
}

void Form::replaceField(QList<Field*>::size_type idx, Field *f)
{
    Q_D(Form);
    d->fields.replace(idx, f);
}

void Form::removeLastField()
{
    Q_D(Form);
    d->fields.removeLast();
}

QList<Field*> Form::fieldList() const noexcept
{
    Q_D(const Form);
    return d->fields.list();
}

QMap<QString, Field*> Form::fieldNameMap() const noexcept
{
    Q_D(const Form);
    return d->fields.nameMap();
}

QMap<QString, Field*> Form::fieldIdMap() const noexcept
{
    Q_D(const Form);
    return d->fields.idMap();
}

QQmlListProperty<CutelystForms::Fieldset> Form::fieldsets()
{
    Q_D(Form);
    return {this, nullptr,
        &FormPrivate::appendFieldset,
        &FormPrivate::fieldsetCount,
        &FormPrivate::fieldset,
        &FormPrivate::clearFieldsets,
        &FormPrivate::replaceFieldset,
        &FormPrivate::removeLastFieldset
    };
}

void Form::appendFieldset(Fieldset *fieldset)
{
    Q_D(Form);
    d->fieldsets.append(fieldset);
}

QList<Fieldset*>::size_type Form::fieldsetCount() const noexcept
{
    Q_D(const Form);
    return d->fieldsets.count();
}

Fieldset* Form::fieldset(QList<Fieldset*>::size_type idx) const
{
    Q_D(const Form);
    return d->fieldsets.item(idx);
}

Fieldset* Form::fieldsetByName(const QString &name) const
{
    Q_D(const Form);
    return d->fieldsets.itemByName(name);
}

Fieldset* Form::fieldsetById(const QString &id) const
{
    Q_D(const Form);
    return d->fieldsets.itemById(id);
}

void Form::clearFieldsets()
{
    Q_D(Form);
    d->fieldsets.clear();
}

void Form::replaceFieldset(QList<Fieldset*>::size_type idx, Fieldset *f)
{
    Q_D(Form);
    d->fieldsets.replace(idx, f);
}

void Form::removeLastFieldset()
{
    Q_D(Form);
    d->fieldsets.removeLast();
}

QList<Fieldset*> Form::fieldsetList() const noexcept
{
    Q_D(const Form);
    return d->fieldsets.list();
}

QMap<QString, Fieldset*> Form::fieldsetNameMap() const noexcept
{
    Q_D(const Form);
    return d->fieldsets.nameMap();
}

QMap<QString, Fieldset*> Form::fieldsetIdMap() const noexcept
{
    Q_D(const Form);
    return d->fieldsets.idMap();
}

QQmlListProperty<CutelystForms::Button> Form::buttons()
{
    Q_D(Form);
    return {this, nullptr,
        &FormPrivate::appendButton,
        &FormPrivate::buttonCount,
        &FormPrivate::button,
        &FormPrivate::clearButtons,
        &FormPrivate::replaceButton,
        &FormPrivate::removeLastButton
    };
}

void Form::appendButton(Button *button)
{
    Q_D(Form);
    d->buttons.append(button);
}

QList<Button*>::size_type Form::buttonCount() const noexcept
{
    Q_D(const Form);
    return d->buttons.count();
}

Button* Form::button(QList<Button*>::size_type idx) const
{
    Q_D(const Form);
    return d->buttons.item(idx);
}

Button* Form::buttonByName(const QString &name) const
{
    Q_D(const Form);
    return d->buttons.itemByName(name);
}

Button* Form::buttonById(const QString &id) const
{
    Q_D(const Form);
    return d->buttons.itemById(id);
}

void Form::clearButtons()
{
    Q_D(Form);
    d->buttons.clear();
}

void Form::replaceButton(QList<Button*>::size_type idx, Button *b)
{
    Q_D(Form);
    d->buttons.replace(idx, b);
}

void Form::removeLastButton()
{
    Q_D(Form);
    d->buttons.removeLast();
}

QList<Button*> Form::buttonList() const noexcept
{
    Q_D(const Form);
    return d->buttons.list();
}

QMap<QString, Button*> Form::buttonNameMap() const noexcept
{
    Q_D(const Form);
    return d->buttons.nameMap();
}

QMap<QString, Button*> Form::buttonIdMap() const noexcept
{
    Q_D(const Form);
    return d->buttons.idMap();
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
