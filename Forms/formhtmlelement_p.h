/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMHTMLELEMENT_P_H
#define C_FORMHTMLELEMENT_P_H

#include "formhtmlelement.h"

#include <Cutelyst/context.h>

#include <QDateTime>

namespace CutelystForms {

class FormHtmlElementPrivate
{
public:
    enum class Tag {
        None,
        Button,
        Fieldset,
        Form,
        Input,
        Keygen,
        Legend,
        Optgroup,
        Option,
        Select,
        Textarea
    };

    FormHtmlElementPrivate(Tag _tag, FormHtmlElement *q);
    virtual ~FormHtmlElementPrivate() = default;

    virtual QStringList attrList() const;

    QDateTime convertedDateTime(const QDateTime &dt) const;

    QString getForm() const;

    FormHtmlElement *q_ptr;

    QString accesskey;
    QString form;
    QString htmlId;
    QString htmlClass;
    QString title;

    Cutelyst::Context *context{nullptr};

    Tag tag{Tag::None};
    bool hidden{false};
    bool spellcheck{false};

private:
    Q_DECLARE_PUBLIC(FormHtmlElement) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(FormHtmlElementPrivate)
};

} // namespace CutelystForms

#endif // C_FORMHTMLELEMENT_P_H
