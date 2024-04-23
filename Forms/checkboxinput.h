/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_CHECKBOXINPUT_H
#define C_FORMS_CHECKBOXINPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"

#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class CheckboxInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT CheckboxInput : public Field
{
    Q_OBJECT
    QML_NAMED_ELEMENT(CheckBoxForm)
public:
    explicit CheckboxInput(QObject *parent = nullptr);
    ~CheckboxInput() override = default;

    [[nodiscard]] Field::Type type() const noexcept override;

    [[nodiscard]] QString typeString() const noexcept override;

private:
    Q_DISABLE_COPY(CheckboxInput)
    Q_DECLARE_PRIVATE(CheckboxInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_FORMS_CHECKBOXINPUT_H
