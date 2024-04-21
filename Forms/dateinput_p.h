/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_DATEINPUT_P_H
#define C_FORMS_DATEINPUT_P_H

#include "dateinput.h"
#include "field_p.h"

namespace CutelystForms {

class DateInputPrivate : public FieldPrivate
{
public:
    DateInputPrivate(DateInput *q);
    ~DateInputPrivate() override = default;

private:
    Q_DECLARE_PUBLIC(DateInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(DateInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_DATEINPUT_P_H
