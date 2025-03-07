/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_TEXTAREA_P_H
#define C_FORMS_TEXTAREA_P_H

#include "field_p.h"
#include "textarea.h"

namespace CutelystForms {

class TextareaPrivate : public FieldPrivate
{
public:
    explicit TextareaPrivate(Textarea *q);
    ~TextareaPrivate() override = default;

    [[nodiscard]] QStringList attrList() const override;

private:
    Q_DECLARE_PUBLIC(Textarea) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(TextareaPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_TEXTAREA_P_H
