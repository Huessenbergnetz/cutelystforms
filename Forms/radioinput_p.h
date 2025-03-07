/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_RADIOINPUT_P_H
#define C_FORMS_RADIOINPUT_P_H

#include "field_p.h"
#include "radioinput.h"

namespace CutelystForms {

class RadioInputPrivate : public FieldPrivate
{
public:
    explicit RadioInputPrivate(RadioInput *q);
    ~RadioInputPrivate() override = default;

    [[nodiscard]] QStringList attrList() const override;

private:
    Q_DECLARE_PUBLIC(RadioInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(RadioInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_RADIOINPUT_P_H
