/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
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
    explicit ButtonPrivate(Button *q);
    ~ButtonPrivate() override = default;

    [[nodiscard]] QString formenctypeString() const;
    [[nodiscard]] QString formmethodString() const;
    [[nodiscard]] QString formtargetString() const;
    [[nodiscard]] QString typeString() const;
    [[nodiscard]] QStringList attrList() const override;

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

} // namespace CutelystForms

#endif // C_BUTTON_P_H
