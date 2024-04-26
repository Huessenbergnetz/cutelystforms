/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_TEXTAREA_H
#define C_FORMS_TEXTAREA_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"

#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class TextareaPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Textarea : public Field
{
    Q_OBJECT
    QML_NAMED_ELEMENT(TextAreaForm)
public:
    explicit Textarea(QObject *parent = nullptr);
    ~Textarea() override = default;

    [[nodiscard]] QString tagName() const noexcept override;

    [[nodiscard]] QString tmpl() const noexcept override;

protected:
    Textarea(TextareaPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Textarea)
    Q_DECLARE_PRIVATE(Textarea) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_FORMS_TEXTAREA_H
