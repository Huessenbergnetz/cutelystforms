/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_EMAILINPUT_P_H
#define C_FORMS_EMAILINPUT_P_H

#include "emailinput.h"
#include "input_p.h"

namespace CutelystForms {

class EmailInputPrivate : public InputPrivate
{
public:
    EmailInputPrivate(EmailInput *q);
    ~EmailInputPrivate() override = default;

    QString value;

private:
    Q_DECLARE_PUBLIC(EmailInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(EmailInputPrivate)
};

}

#endif // C_FORMS_EMAILINPUT_P_H
