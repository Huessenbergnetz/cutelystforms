/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_HIDDENINPUT_H
#define C_FORMS_HIDDENINPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "input.h"
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class HiddenInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT HiddenInput : public Input
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value WRITE setValue)
    QML_ELEMENT
public:
    explicit HiddenInput(QObject *parent = nullptr);
    ~HiddenInput() override = default;

    Q_REQUIRED_RESULT QString value() const noexcept;
    void setValue(const QString &value) noexcept;

    Q_REQUIRED_RESULT Input::Type type() const noexcept override;

    Q_REQUIRED_RESULT QString typeString() const noexcept override;

    Q_REQUIRED_RESULT QString valueString() const noexcept override;

private:
    Q_DISABLE_COPY(HiddenInput)
    Q_DECLARE_PRIVATE(HiddenInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_HIDDENINPUT_H
