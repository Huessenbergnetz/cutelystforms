/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_TIMEINPUT_P_H
#define C_FORMS_TIMEINPUT_P_H

#include "field_p.h"
#include "timeinput.h"

namespace CutelystForms {

class TimeInputPrivate : public FieldPrivate
{
public:
    TimeInputPrivate(TimeInput *q);
    ~TimeInputPrivate() override = default;

private:
    Q_DECLARE_PUBLIC(TimeInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(TimeInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_TIMEINPUT_P_H
