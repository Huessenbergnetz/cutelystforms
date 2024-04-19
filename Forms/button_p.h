/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_BUTTON_P_H
#define C_BUTTON_P_H

#include "button.h"
#include "formhtmlelement_p.h"

namespace CutelystForms {

class ButtonPrivate : public FormHtmlElementPrivate
{
public:
    ButtonPrivate(Button *q);
    ~ButtonPrivate() override = default;

    QString name;
    QString text;
    QString value;

    Button::Type type = Button::Submit;

    bool disabled{false};

private:
    Q_DECLARE_PUBLIC(Button) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(ButtonPrivate)
};

}

#endif // C_BUTTON_P_H
