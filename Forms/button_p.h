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

    QString formenctypeString() const;
    QString formmethodString() const;
    QString formtargetString() const;
    QString typeString() const;
    virtual QStringList attrList() const override;

    QVariant value;
    QUrl formaction;
    QString name;
    QString text;

    Button::EncType formenctype{Button::NoEncType};
    Button::Method formmethod{Button::NoMethod};
    Button::Target formtarget{Button::NoTarget};
    Button::Type type{Button::Submit};

    bool disabled{false};
    bool formnovalidate{false};

private:
    Q_DECLARE_PUBLIC(Button) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(ButtonPrivate)
};

}

#endif // C_BUTTON_P_H
