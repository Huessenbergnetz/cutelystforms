/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_TEXTINPUT_P_H
#define C_FORMS_TEXTINPUT_P_H

#include "textinput.h"
#include "field_p.h"

namespace CutelystForms {

class TextInputPrivate : public FieldPrivate
{
public:
    TextInputPrivate(TextInput *q);
    ~TextInputPrivate() override = default;

    QString value;

private:
    Q_DECLARE_PUBLIC(TextInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(TextInputPrivate)
};

}

#endif // C_FORMS_TEXTINPUT_P_H
