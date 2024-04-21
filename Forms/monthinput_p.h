/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_MONTHINPUT_P_H
#define C_FORMS_MONTHINPUT_P_H

#include "field_p.h"
#include "monthinput.h"

namespace CutelystForms {

class MonthInputPrivate : public FieldPrivate
{
public:
    MonthInputPrivate(MonthInput *q);
    ~MonthInputPrivate() override = default;

private:
    Q_DECLARE_PUBLIC(MonthInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(MonthInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_MONTHINPUT_P_H
