/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_INPUT_P_H
#define C_FORMS_INPUT_P_H

#include "input.h"
#include "field_p.h"

namespace CutelystForms {

class InputPrivate : public FieldPrivate
{
public:
    InputPrivate(Input *q);
    ~InputPrivate() override = default;

private:
    Q_DECLARE_PUBLIC(Input) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(InputPrivate)
};

}

#endif // C_FORMS_INPUT_P_H
