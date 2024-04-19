/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "formhtmlelement_p.h"

using namespace CutelystForms;

FormHtmlElementPrivate::FormHtmlElementPrivate(FormHtmlElement *q) :
    q_ptr(q)
{

}

FormHtmlElement::FormHtmlElement(QObject *parent) :
    QObject(parent), d_ptr(new FormHtmlElementPrivate(this))
{

}

FormHtmlElement::FormHtmlElement(FormHtmlElementPrivate &dd, QObject *parent) :
    QObject(parent), d_ptr(&dd)
{

}

// can not be defaulted as that could create an inline
// descrustor that is not compatible with forward declared
// private class and QScopedPointer
FormHtmlElement::~FormHtmlElement() // NOLINT(modernize-use-equals-default)
{

}

QString FormHtmlElement::htmlId() const noexcept
{
    Q_D(const FormHtmlElement);
    return d->htmlId;
}

void FormHtmlElement::setHtmlId(const QString &htmlId) noexcept
{
    Q_D(FormHtmlElement);
    d->htmlId = htmlId;
}

QString FormHtmlElement::htmlClass() const noexcept
{
    Q_D(const FormHtmlElement);
    return d->htmlClass;
}

void FormHtmlElement::setHtmlClass(const QString &htmlClass) noexcept
{
    Q_D(FormHtmlElement);
    d->htmlClass = htmlClass;
}

QString FormHtmlElement::accesskey() const noexcept
{
    Q_D(const FormHtmlElement);
    return d->accesskey;
}

void FormHtmlElement::setAccesskey(const QString &accesskey) noexcept
{
    Q_D(FormHtmlElement);
    d->accesskey = accesskey;
}

bool FormHtmlElement::isContenteditable() const noexcept
{
    Q_D(const FormHtmlElement);
    return d->contenteditable;
}

void FormHtmlElement::setContenteditable(bool contenteditable) noexcept
{
    Q_D(FormHtmlElement);
    d->contenteditable = contenteditable;
}

CutelystForms::FormHtmlElement::DraggableState FormHtmlElement::draggable() const noexcept
{
    Q_D(const FormHtmlElement);
    return d->draggable;
}

void FormHtmlElement::setDraggable(CutelystForms::FormHtmlElement::DraggableState draggable) noexcept
{
    Q_D(FormHtmlElement);
    d->draggable = draggable;
}

bool FormHtmlElement::isHidden() const noexcept
{
    Q_D(const FormHtmlElement);
    return d->hidden;
}

void FormHtmlElement::setHidden(bool hidden) noexcept
{
    Q_D(FormHtmlElement);
    d->hidden = hidden;
}

bool FormHtmlElement::spellcheck() const noexcept
{
    Q_D(const FormHtmlElement);
    return d->spellcheck;
}

void FormHtmlElement::setSpellcheck(bool spellcheck) noexcept
{
    Q_D(FormHtmlElement);
    d->spellcheck = spellcheck;
}

int FormHtmlElement::tabindex() const noexcept
{
    Q_D(const FormHtmlElement);
    return d->tabindex;
}

void FormHtmlElement::setTabindex(int tabindex) noexcept
{
    Q_D(FormHtmlElement);
    d->tabindex = tabindex;
}

QString FormHtmlElement::title() const noexcept
{
    Q_D(const FormHtmlElement);
    return d->title;
}

void FormHtmlElement::setTitle(const QString &title) noexcept
{
    Q_D(FormHtmlElement);
    d->title = title;
}

QString FormHtmlElement::tagName() const noexcept
{
    return {};
}

#include "moc_formhtmlelement.cpp"
