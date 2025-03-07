/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_SEARCHINPUT_P_H
#define C_FORMS_SEARCHINPUT_P_H

#include "field_p.h"
#include "searchinput.h"

namespace CutelystForms {

class SearchInputPrivate : public FieldPrivate
{
public:
    explicit SearchInputPrivate(SearchInput *q);
    ~SearchInputPrivate() override = default;

    [[nodiscard]] QStringList attrList() const override;

private:
    Q_DECLARE_PUBLIC(SearchInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(SearchInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_SEARCHINPUT_P_H
