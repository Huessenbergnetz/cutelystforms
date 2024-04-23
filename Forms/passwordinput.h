/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_PASSWORDINPUT_H
#define C_FORMS_PASSWORDINPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"

#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class PasswordInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT PasswordInput : public Field
{
    Q_OBJECT
    QML_NAMED_ELEMENT(PasswordForm)
public:
    explicit PasswordInput(QObject *parent = nullptr);
    ~PasswordInput() override = default;

    [[nodiscard]] Field::Type type() const noexcept override;

    [[nodiscard]] QString typeString() const noexcept override;

private:
    Q_DISABLE_COPY(PasswordInput)
    Q_DECLARE_PRIVATE(PasswordInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_FORMS_PASSWORDINPUT_H
