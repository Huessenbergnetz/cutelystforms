/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_URLINPUT_P_H
#define C_FORMS_URLINPUT_P_H

#include "field_p.h"
#include "urlinput.h"

namespace CutelystForms {

class UrlInputPrivate : public FieldPrivate
{
public:
    UrlInputPrivate(UrlInput *q);
    ~UrlInputPrivate() override = default;

private:
    Q_DECLARE_PUBLIC(UrlInput) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(UrlInputPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_URLINPUT_P_H
