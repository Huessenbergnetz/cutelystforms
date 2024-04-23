/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_DATEIPUT_H
#define C_FORMS_DATEIPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"

#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class DateInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT DateInput : public Field
{
    Q_OBJECT
    QML_NAMED_ELEMENT(DateForm)
public:
    explicit DateInput(QObject *parent = nullptr);
    ~DateInput() override = default;

    [[nodiscard]] Field::Type type() const noexcept override;

    [[nodiscard]] QString typeString() const noexcept override;

private:
    Q_DISABLE_COPY(DateInput)
    Q_DECLARE_PRIVATE(DateInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_FORMS_DATEIPUT_H
