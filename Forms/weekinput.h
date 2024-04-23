/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_WEEKINPUT_H
#define C_FORMS_WEEKINPUT_H

#include "field.h"

#include <QQmlEngine>

namespace CutelystForms {

class WeekInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT WeekInput : public Field
{
    Q_OBJECT
    QML_NAMED_ELEMENT(WeekForm)
public:
    explicit WeekInput(QObject *parent = nullptr);
    ~WeekInput() override = default;

    [[nodiscard]] Field::Type type() const noexcept override;

    [[nodiscard]] QString typeString() const noexcept override;

private:
    Q_DISABLE_COPY(WeekInput)
    Q_DECLARE_PRIVATE(WeekInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_FORMS_WEEKINPUT_H
