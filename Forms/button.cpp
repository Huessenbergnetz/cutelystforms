/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button_p.h"

using namespace CutelystForms;

ButtonPrivate::ButtonPrivate(Button *q) :
    FormHtmlElementPrivate(Tag::Button ,q)
{

}

QString ButtonPrivate::formenctypeString() const
{
    switch (formenctype) {
    case Button::WwwFormUrlEncoded:
        return u"application/x-www-form-urlencoded"_qs;
    case Button::MultipartFormData:
        return u"multipart/form-data"_qs;
    case Button::TextPlain:
        return u"text/plain"_qs;
    default:
        return {};
    }
}

QString ButtonPrivate::formmethodString() const
{
    switch (formmethod) {
    case Button::Get:
        return u"get"_qs;
    case Button::Post:
        return u"post"_qs;
    default:
        return {};
    }
}

QString ButtonPrivate::formtargetString() const
{
    switch (formtarget) {
    case Button::Self:
        return u"_self"_qs;
    case Button::Blank:
        return u"_blank"_qs;
    case Button::Parent:
        return u"_parent"_qs;
    case Button::Top:
        return u"_top"_qs;
    default:
        return {};
    }
}

QString ButtonPrivate::typeString() const
{
    switch(type) {
    case Button::Submit:
        return u"submit"_qs;
    case Button::Reset:
        return u"reset"_qs;
    case Button::Btn:
        return u"button"_qs;
    }

    Q_UNREACHABLE();
    return {};
}

QStringList ButtonPrivate::attrList() const
{
    QStringList lst = FormHtmlElementPrivate::attrList();

    if (disabled) {
        lst.append(u"disabled"_qs);
    }
    if (formaction.isValid()) {
        lst.append(u"formaction=\""_qs + formaction.toString(QUrl::FullyEncoded) + QLatin1Char('"'));
    }
    if (formenctype != Button::NoEncType) {
        lst.append(u"formenctype=\""_qs + formenctypeString() + QLatin1Char('"'));
    }
    if (formmethod != Button::NoMethod) {
        lst.append(u"formmethod=\""_qs + formmethodString() + QLatin1Char('"'));
    }
    if (formnovalidate) {
        lst.append(u"formnovalidate"_qs);
    }
    if (formtarget != Button::NoTarget) {
        lst.append(u"formtarget=\""_qs + formtargetString() + QLatin1Char('"'));
    }
    if (name.isEmpty()) {
        lst.append(u"name=\""_qs + name + QLatin1Char('"'));
    }
    if (value.isValid()) {
        lst.append(u"value=\""_qs + value.toString() + QLatin1Char('"'));
    }

    return lst;
}

Button::Button(QObject *parent) :
    FormHtmlElement(* new ButtonPrivate(this), parent)
{

}

Button::Button(ButtonPrivate &dd, QObject *parent) :
    FormHtmlElement(dd, parent)
{

}

bool Button::isDisabled() const noexcept
{
    Q_D(const Button);
    return d->disabled;
}

void Button::setDisabled(bool disabled) noexcept
{
    Q_D(Button);
    d->disabled = disabled;
}

QUrl Button::formaction() const noexcept
{
    Q_D(const Button);
    return d->formaction;
}

void Button::setFormaction(const QUrl &formaction) noexcept
{
    Q_D(Button);
    d->formaction = formaction;
}

CutelystForms::Button::EncType Button::formenctype() const noexcept
{
    Q_D(const Button);
    return d->formenctype;
}

void Button::setFormenctype(CutelystForms::Button::EncType formenctype) noexcept
{
    Q_D(Button);
    d->formenctype = formenctype;
}

QString Button::formenctypeString() const
{
    Q_D(const Button);
    return d->formenctypeString();
}

CutelystForms::Button::Method Button::formmethod() const noexcept
{
    Q_D(const Button);
    return d->formmethod;
}

void Button::setFormmethod(CutelystForms::Button::Method formmethod) noexcept
{
    Q_D(Button);
    d->formmethod = formmethod;
}

QString Button::formmethodString() const
{
    Q_D(const Button);
    return d->formmethodString();
}

bool Button::formnovalidate() const noexcept
{
    Q_D(const Button);
    return d->formnovalidate;
}

void Button::setFormnovalidate(bool formnovalidate) noexcept
{
    Q_D(Button);
    d->formnovalidate = formnovalidate;
}

CutelystForms::Button::Target Button::formtarget() const noexcept
{
    Q_D(const Button);
    return d->formtarget;
}

void Button::setFormtarget(CutelystForms::Button::Target formtarget) noexcept
{
    Q_D(Button);
    d->formtarget = formtarget;
}

QString Button::formtargetString() const
{
    Q_D(const Button);
    return d->formtargetString();
}

QString Button::name() const noexcept
{
    Q_D(const Button);
    return d->name;
}

void Button::setName(const QString &name) noexcept
{
    Q_D(Button);
    d->name = name;
}

CutelystForms::Button::Type Button::type() const noexcept
{
    Q_D(const Button);
    return d->type;
}

void Button::setType(CutelystForms::Button::Type type) noexcept
{
    Q_D(Button);
    d->type = type;
}

QString Button::typeString() const
{
    Q_D(const Button);
    return d->typeString();
}

QString Button::tagName() const noexcept
{
    return QStringLiteral("button");
}

QString Button::text() const noexcept
{
    Q_D(const Button);
    return d->text;
}

void Button::setText(const QString &text) noexcept
{
    Q_D(Button);
    d->text = text;
}

QVariant Button::value() const noexcept
{
    Q_D(const Button);
    return d->value;
}

void Button::setValue(const QVariant &value) noexcept
{
    Q_D(Button);
    d->value = value;
}

#include "moc_button.cpp"
