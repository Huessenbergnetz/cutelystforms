/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_TIMEINPUT_H
#define C_FORMS_TIMEINPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"

#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class TimeInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT TimeInput : public Field
{
    Q_OBJECT
    QML_NAMED_ELEMENT(TimeForm)
public:
    explicit TimeInput(QObject *parent = nullptr);
    ~TimeInput() override = default;

    [[nodiscard]] Field::Type type() const noexcept override;

    [[nodiscard]] QString typeString() const noexcept override;

private:
    Q_DISABLE_COPY(TimeInput)
    Q_DECLARE_PRIVATE(TimeInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_FORMS_TIMEINPUT_H
