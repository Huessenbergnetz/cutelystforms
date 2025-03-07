/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_FILEINPUT_P_H
#define C_FORMS_FILEINPUT_P_H

#include "field_p.h"
#include "fileinput.h"

namespace CutelystForms {

class FileInputPrivate : public FieldPrivate
{
public:
    explicit FileInputPrivate(FileInput *q);
    ~FileInputPrivate() override = default;

    [[nodiscard]] QStringList attrList() const override;

private:
    Q_DECLARE_PUBLIC(FileInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(FileInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_FILEINPUT_P_H
