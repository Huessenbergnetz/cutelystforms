/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_SEARCHINPUT_H
#define C_FORMS_SEARCHINPUT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"
#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class SearchInputPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT SearchInput : public Field
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit SearchInput(QObject *parent = nullptr);
    ~SearchInput() override = default;

    [[nodiscard]] Field::Type type() const noexcept override;

    [[nodiscard]] QString typeString() const noexcept override;

private:
    Q_DISABLE_COPY(SearchInput)
    Q_DECLARE_PRIVATE(SearchInput) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_SEARCHINPUT_H
