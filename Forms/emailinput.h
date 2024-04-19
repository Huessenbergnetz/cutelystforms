/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_EMAILINPUT_H
#define C_FORMS_EMAILINPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class EmailInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT EmailInput : public Field
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit EmailInput(QObject *parent = nullptr);
    ~EmailInput() override = default;

    [[nodiscard]] Field::Type type() const noexcept override;

    [[nodiscard]] QString typeString() const noexcept override;

private:
    Q_DISABLE_COPY(EmailInput)
    Q_DECLARE_PRIVATE(EmailInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_EMAILINPUT_H