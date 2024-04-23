/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_URLINPUT_H
#define C_FORMS_URLINPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"

#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class UrlInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT UrlInput : public Field
{
    Q_OBJECT
    QML_NAMED_ELEMENT(UrlForm)
public:
    explicit UrlInput(QObject *parent = nullptr);
    ~UrlInput() override = default;

    [[nodiscard]] Field::Type type() const noexcept override;

    [[nodiscard]] QString typeString() const noexcept override;

private:
    Q_DISABLE_COPY(UrlInput)
    Q_DECLARE_PRIVATE(UrlInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_FORMS_URLINPUT_H
