/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_HIDDENINPUT_P_H
#define C_FORMS_HIDDENINPUT_P_H

#include "hiddeninput.h"
#include "field_p.h"

namespace CutelystForms {

class HiddenInputPrivate : public FieldPrivate
{
public:
    HiddenInputPrivate(HiddenInput *q);
    ~HiddenInputPrivate() override = default;

    QString value;

private:
    Q_DECLARE_PUBLIC(HiddenInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(HiddenInputPrivate)
};

}

#endif // C_FORMS_HIDDENINPUT_P_H
