/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_WEEKINPUT_P_H
#define C_FORMS_WEEKINPUT_P_H

#include "field_p.h"
#include "weekinput.h"

namespace CutelystForms {

class WeekInputPrivate : public FieldPrivate
{
public:
    explicit WeekInputPrivate(WeekInput *q);
    ~WeekInputPrivate() override = default;

    [[nodiscard]] QStringList attrList() const override;
    [[nodiscard]] QString getValueString() const override;

private:
    [[nodiscard]] QString getWeekString(const QVariant &v) const;

    Q_DECLARE_PUBLIC(WeekInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(WeekInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_WEEKINPUT_P_H
