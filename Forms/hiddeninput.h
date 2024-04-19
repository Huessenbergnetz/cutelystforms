/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_HIDDENINPUT_H
#define C_FORMS_HIDDENINPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class HiddenInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT HiddenInput : public Field
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit HiddenInput(QObject *parent = nullptr);
    ~HiddenInput() override = default;

    Q_REQUIRED_RESULT Field::Type type() const noexcept override;

    Q_REQUIRED_RESULT QString typeString() const noexcept override;

private:
    Q_DISABLE_COPY(HiddenInput)
    Q_DECLARE_PRIVATE(HiddenInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_HIDDENINPUT_H
