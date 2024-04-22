/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_TELINPUT_P_H
#define C_FORMS_TELINPUT_P_H

#include "field_p.h"
#include "telinput.h"

namespace CutelystForms {

class TelInputPrivate : public FieldPrivate
{
public:
    TelInputPrivate(TelInput *q);
    ~TelInputPrivate() override = default;

    QStringList attrList() const override;

private:
    Q_DECLARE_PUBLIC(TelInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(TelInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_TELINPUT_P_HTELINPUT_P_H
