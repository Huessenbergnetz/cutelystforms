/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_COLORINPUT_H
#define C_FORMS_COLORINPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"

#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class ColorInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT ColorInput : public Field
{
    Q_OBJECT
    QML_NAMED_ELEMENT(ColorForm)
public:
    explicit ColorInput(QObject *parent = nullptr);
    ~ColorInput() override = default;

    [[nodiscard]] Field::Type type() const noexcept override;

    [[nodiscard]] QString typeString() const noexcept override;

private:
    Q_DISABLE_COPY(ColorInput)
    Q_DECLARE_PRIVATE(ColorInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // COLORINPUT_H
