/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMHTMLELEMENT_P_H
#define C_FORMHTMLELEMENT_P_H

#include "formhtmlelement.h"

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
        Legend,
        Optgroup,
        Option,
        Select,
        Textarea
    };

    FormHtmlElementPrivate(Tag _tag, FormHtmlElement *q);
    virtual ~FormHtmlElementPrivate() = default;

    virtual QStringList attrList() const;

    FormHtmlElement *q_ptr;

    QString htmlId;
    QString htmlClass;
    QString accesskey;
    QString title;

    int tabindex{0};
    Tag tag{Tag::None};
    bool hidden{false};
    bool spellcheck{true};

private:
    Q_DECLARE_PUBLIC(FormHtmlElement) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(FormHtmlElementPrivate)
};

}

#endif // C_FORMHTMLELEMENT_P_H
