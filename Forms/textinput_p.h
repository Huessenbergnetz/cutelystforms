/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_TEXTINPUT_P_H
#define C_FORMS_TEXTINPUT_P_H

#include "field_p.h"
#include "textinput.h"

namespace CutelystForms {

class TextInputPrivate : public FieldPrivate
{
public:
    TextInputPrivate(TextInput *q);
    ~TextInputPrivate() override = default;

    QStringList attrList() const override;

private:
    Q_DECLARE_PUBLIC(TextInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(TextInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_TEXTINPUT_P_H
