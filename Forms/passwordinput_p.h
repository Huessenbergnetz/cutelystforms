/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_PASSWORDINPUT_P_H
#define C_FORMS_PASSWORDINPUT_P_H

#include "field_p.h"
#include "passwordinput.h"

namespace CutelystForms {

class PasswordInputPrivate : public FieldPrivate
{
public:
    PasswordInputPrivate(PasswordInput *q);
    ~PasswordInputPrivate() override = default;

private:
    Q_DECLARE_PUBLIC(PasswordInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(PasswordInputPrivate)
};

} // namespace CutelystForms

#endif // PASSWORDINPUT_P_H
