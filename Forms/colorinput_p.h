/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_COLORINPUT_P_H
#define C_FORMS_COLORINPUT_P_H

#include "colorinput.h"
#include "field_p.h"

namespace CutelystForms {

class ColorInputPrivate : public FieldPrivate
{
public:
    explicit ColorInputPrivate(ColorInput *q);
    ~ColorInputPrivate() override = default;

    [[nodiscard]] QStringList attrList() const override;

private:
    Q_DECLARE_PUBLIC(ColorInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(ColorInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_COLORINPUT_P_H
