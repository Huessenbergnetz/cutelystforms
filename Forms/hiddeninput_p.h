/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_HIDDENINPUT_P_H
#define C_FORMS_HIDDENINPUT_P_H

#include "field_p.h"
#include "hiddeninput.h"

namespace CutelystForms {

class HiddenInputPrivate : public FieldPrivate
{
public:
    explicit HiddenInputPrivate(HiddenInput *q);
    ~HiddenInputPrivate() override = default;

private:
    Q_DECLARE_PUBLIC(HiddenInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(HiddenInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_HIDDENINPUT_P_H
