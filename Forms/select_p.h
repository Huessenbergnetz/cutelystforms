/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_SELECT_P_H
#define C_FORMS_SELECT_P_H

#include "select.h"
#include "field_p.h"

namespace CutelystForms {

class SelectPrivate : public FieldPrivate
{
public:
    SelectPrivate(Select *q);
    ~SelectPrivate() override = default;

    QList<SelectContent*> content;
    int size{0};
    bool multiple{false};

private:
    Q_DECLARE_PUBLIC(Select) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(SelectPrivate)
};

}

#endif // C_FORMS_SELECT_P_H
