/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_TEXTINPUT_H
#define C_FORMS_TEXTINPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "input.h"
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class TextInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT TextInput : public Input
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value WRITE setValue)
    QML_ELEMENT
public:
    explicit TextInput(QObject *parent = nullptr);
    ~TextInput() override = default;

    [[nodiscard]] QString value() const noexcept;
    void setValue(const QString &value) noexcept;

    [[nodiscard]] Input::Type type() const noexcept override;

    [[nodiscard]] QString typeString() const noexcept override;

    [[nodiscard]] QString valueString() const noexcept override;

private:
    Q_DISABLE_COPY(TextInput)
    Q_DECLARE_PRIVATE(TextInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_TEXTINPUT_H
