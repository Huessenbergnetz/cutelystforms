/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_NUMBERINPUT_P_H
#define C_FORMS_NUMBERINPUT_P_H

#include "field_p.h"
#include "numberinput.h"

namespace CutelystForms {

class NumberInputPrivate : public FieldPrivate
{
public:
    explicit NumberInputPrivate(NumberInput *q);
    ~NumberInputPrivate() override = default;

    [[nodiscard]] QStringList attrList() const override;

private:
    Q_DECLARE_PUBLIC(NumberInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(NumberInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_NUMBERINPUT_P_H
