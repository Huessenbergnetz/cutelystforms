/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "button_p.h"

using namespace CutelystForms;

ButtonPrivate::ButtonPrivate(Button *q) :
    FormHtmlElementPrivate(q)
{

}

Button::Button(QObject *parent) :
    FormHtmlElement(* new ButtonPrivate(this), parent)
{

}

Button::Button(ButtonPrivate &dd, QObject *parent) :
    FormHtmlElement(dd, parent)
{

}

bool Button::autofocus() const noexcept
{
    Q_D(const Button);
    return d->autocofus;
}

void Button::setAutofocus(bool autofocus) noexcept
{
    Q_D(Button);
    d->autocofus = autofocus;
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

QString Button::value() const noexcept
{
    Q_D(const Button);
    return d->value;
}

void Button::setValue(const QString &value) noexcept
{
    Q_D(Button);
    d->value = value;
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

#include "moc_button.cpp"
