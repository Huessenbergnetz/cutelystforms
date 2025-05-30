/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_DATETIMELOCALINPUT_P_H
#define C_FORMS_DATETIMELOCALINPUT_P_H

#include "datetimelocalinput.h"
#include "field_p.h"

namespace CutelystForms {

class DateTimeLocalInputPrivate : public FieldPrivate
{
public:
    explicit DateTimeLocalInputPrivate(DateTimeLocalInput *q);
    ~DateTimeLocalInputPrivate() override = default;

    [[nodiscard]] QStringList attrList() const override;
    [[nodiscard]] QString getValueString() const override;

private:
    [[nodiscard]] QString getDateTimeString(const QVariant &v) const;

    Q_DECLARE_PUBLIC(DateTimeLocalInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(DateTimeLocalInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_DATETIMELOCALINPUT_P_H
