/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_CHECKBOXINPUT_P_H
#define C_FORMS_CHECKBOXINPUT_P_H

#include "checkboxinput.h"
#include "field_p.h"

namespace CutelystForms {

class CheckboxInputPrivate : public FieldPrivate
{
public:
    explicit CheckboxInputPrivate(CheckboxInput *q);
    ~CheckboxInputPrivate() override = default;

    [[nodiscard]] QStringList attrList() const override;

private:
    Q_DECLARE_PUBLIC(CheckboxInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(CheckboxInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_CHECKBOXINPUT_P_H
