/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_SELECT_P_H
#define C_FORMS_SELECT_P_H

#include "field_p.h"
#include "select.h"

namespace CutelystForms {

class SelectPrivate : public FieldPrivate
{
public:
    explicit SelectPrivate(Select *q);
    ~SelectPrivate() override = default;

    [[nodiscard]] QStringList attrList() const override;

private:
    Q_DECLARE_PUBLIC(Select) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(SelectPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_SELECT_P_H
