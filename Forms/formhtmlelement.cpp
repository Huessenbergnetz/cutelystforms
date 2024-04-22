/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "formhtmlelement_p.h"
#include "forms.h"

#include <QTimeZone>

using namespace CutelystForms;

FormHtmlElementPrivate::FormHtmlElementPrivate(Tag _tag, FormHtmlElement *q)
    : q_ptr(q)
    , tag(_tag)
{
}

QStringList FormHtmlElementPrivate::attrList() const
{
    QStringList lst;

    if (!htmlId.isEmpty()) {
        lst.append(u"id=\""_qs + htmlId + QLatin1Char('"'));
    }
    if (!accesskey.isEmpty()) {
        lst.append(u"accesskey=\""_qs + accesskey + QLatin1Char('"'));
    }
    if (!form.isEmpty()) {
        lst.append(u"form=\""_qs + form + QLatin1Char('"'));
    }
    if (hidden) {
        lst.append(u"hidden"_qs);
    }
    if (spellcheck && (tag == Tag::Input || tag == Tag::Textarea)) {
        lst.append(u"spellcheck=\"true\""_qs);
    }
    if (!title.isEmpty()) {
        lst.append(u"title=\""_qs + title + QLatin1Char('"'));
    }

    return lst;
}

QDateTime FormHtmlElementPrivate::convertedDateTime(const QDateTime &dt) const
{
    const QString stashKey = Forms::timezoneStashKey();

    if (!stashKey.isEmpty()) {
        const QVariant v = context->stash(stashKey);
        if (!v.isNull()) {
            QTimeZone tz;
            if (v.canConvert<QTimeZone>()) {
                tz = v.value<QTimeZone>();
            } else if (v.canConvert<QString>()) {
                tz = QTimeZone(v.toString().toLatin1());
            }
            if (tz.isValid()) {
                return dt.toTimeZone(tz);
            }
        }
    }

    return dt;
}

// QString FormHtmlElementPrivate::getForm() const
// {
//     if (!form.isEmpty()) {
//         return form;
//     } else {
//         Q_Q(const FormHtmlElement);
//         if (q->parent()) {
//             auto form = qobject_cast<Form*>(q->parent());
//             if (form) {
//                 return form->htmlId();
//             } else {
//                 auto fieldset = qobject_cast<Fieldset*>(q->parent());
//                 if (fieldset) {
//                     form = qobject_cast<Form*>(fieldset->parent());
//                     if (form) {
//                         return form->htmlId();
//                     }
//                 }
//             }
//         }
//     }

//     return {};
// }

FormHtmlElement::FormHtmlElement(QObject *parent)
    : QObject(parent)
    , d_ptr(new FormHtmlElementPrivate(FormHtmlElementPrivate::Tag::None, this))
{
}

FormHtmlElement::FormHtmlElement(FormHtmlElementPrivate &dd, QObject *parent)
    : QObject(parent)
    , d_ptr(&dd)
{
}

// can not be defaulted as that could create an inline
// descrustor that is not compatible with forward declared
// private class and QScopedPointer
FormHtmlElement::~FormHtmlElement() // NOLINT(modernize-use-equals-default)
{
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

QString FormHtmlElement::attrs() const
{
    Q_D(const FormHtmlElement);
    return d->attrList().join(QChar(QChar::Space));
}

QString FormHtmlElement::form() const noexcept
{
    Q_D(const FormHtmlElement);
    return d->form;
}

void FormHtmlElement::setForm(const QString &form) noexcept
{
    Q_D(FormHtmlElement);
    d->form = form;
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

QString FormHtmlElement::tagName() const noexcept
{
    return {};
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

Cutelyst::Context *FormHtmlElement::context() const noexcept
{
    Q_D(const FormHtmlElement);
    return d->context;
}

void FormHtmlElement::setContext(Cutelyst::Context *c)
{
    Q_D(FormHtmlElement);
    d->context = c;
#if QT_VERSION >= QT_VERSION_CHECK(6, 7, 0)
    const auto children =
        findChildren<CutelystForms::FormHtmlElement *>(Qt::FindDirectChildrenOnly);
#else
    const auto children =
        findChildren<CutelystForms::FormHtmlElement *>(QString(), Qt::FindDirectChildrenOnly);
#endif
    for (auto child : children) {
        child->setContext(c);
    }
}

#include "moc_formhtmlelement.cpp"
