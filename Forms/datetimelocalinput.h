/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_DATETIMELOCALINPUT_H
#define C_FORMS_DATETIMELOCALINPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"

#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class DateTimeLocalInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT DateTimeLocalInput : public Field
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit DateTimeLocalInput(QObject *parent = nullptr);
    ~DateTimeLocalInput() override = default;

    [[nodiscard]] Field::Type type() const noexcept override;

    [[nodiscard]] QString typeString() const noexcept override;

private:
    Q_DISABLE_COPY(DateTimeLocalInput)
    Q_DECLARE_PRIVATE(DateTimeLocalInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_FORMS_DATETIMELOCALINPUT_H
