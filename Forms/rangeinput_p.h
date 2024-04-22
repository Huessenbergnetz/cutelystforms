/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_RANGEINPUT_P_H
#define C_FORMS_RANGEINPUT_P_H

#include "field_p.h"
#include "rangeinput.h"

namespace CutelystForms {

class RangeInputPrivate : public FieldPrivate
{
public:
    RangeInputPrivate(RangeInput *q);
    ~RangeInputPrivate() override = default;

    QStringList attrList() const override;

private:
    Q_DECLARE_PUBLIC(RangeInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(RangeInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_RANGEINPUT_P_H
