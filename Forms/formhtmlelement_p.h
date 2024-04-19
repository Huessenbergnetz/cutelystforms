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
    FormHtmlElementPrivate(FormHtmlElement *q);
    virtual ~FormHtmlElementPrivate() = default;

    FormHtmlElement *q_ptr;

    QString htmlId;
    QString htmlClass;
    QString accesskey;
    QString title;

    int tabindex{-2};
    FormHtmlElement::DraggableState draggable{FormHtmlElement::DragAuto};
    bool contenteditable{false};
    bool hidden{false};
    bool spellcheck{true};

private:
    Q_DECLARE_PUBLIC(FormHtmlElement) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(FormHtmlElementPrivate)
};

}

#endif // C_FORMHTMLELEMENT_P_H
