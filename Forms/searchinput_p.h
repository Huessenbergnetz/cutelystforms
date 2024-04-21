/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_SEARCHINPUT_P_H
#define C_FORMS_SEARCHINPUT_P_H

#include "searchinput.h"
#include "field_p.h"

namespace CutelystForms {

class SearchInputPrivate : public FieldPrivate
{
public:
    SearchInputPrivate(SearchInput *q);
    ~SearchInputPrivate() override = default;

private:
    Q_DECLARE_PUBLIC(SearchInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(SearchInputPrivate)
};

}

#endif // C_FORMS_SEARCHINPUT_P_H
