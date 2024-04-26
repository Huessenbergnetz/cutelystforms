/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_SELECT_H
#define C_FORMS_SELECT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"

#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class SelectPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Select : public Field
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Select(QObject *parent = nullptr);
    ~Select() override = default;

    Q_REQUIRED_RESULT QString tagName() const noexcept override;

    [[nodiscard]] QString tmpl() const noexcept override;

protected:
    Select(SelectPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Select)
    Q_DECLARE_PRIVATE(Select) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_FORMS_SELECT_H
