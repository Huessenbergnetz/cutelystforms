/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_INPUT_H
#define C_FORMS_INPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class InputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Input : public Field
{
    Q_OBJECT
    Q_PROPERTY(CutelystForms::Input::Type type READ type CONSTANT)
    Q_PROPERTY(QString typeString READ typeString CONSTANT)
    QML_ANONYMOUS
public:
    explicit Input(QObject *parent = nullptr);
    ~Input() override = default;

    enum Type {
        Text            = 0,
        Search,
        Password,
        Tel,
        Url,
        Email,
        Number,
        Range,
        Radio,
        Checkbox,
        Hidden,
        File,
        Color,
        Date,
        DatetimeLocal,
        Week,
        Month,
        Time
    };
    Q_ENUM(Type)

    Q_REQUIRED_RESULT virtual Input::Type type() const noexcept;

    Q_REQUIRED_RESULT virtual QString typeString() const noexcept;

    Q_REQUIRED_RESULT QString tagName() const noexcept override;

protected:
    Input(InputPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Input)
    Q_DECLARE_PRIVATE(Input) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_INPUT_H
