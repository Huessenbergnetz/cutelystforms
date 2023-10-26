/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_OPTION_P_H
#define C_FORMS_OPTION_P_H

#include "option.h"
#include "selectcontent_p.h"

namespace CutelystForms {

class OptionPrivate : public SelectContentPrivate
{
public:
    OptionPrivate(Option *q);
    ~OptionPrivate() override = default;

    QString text;
    QString value;
    bool selected{false};

private:
    Q_DECLARE_PUBLIC(Option) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(OptionPrivate)
};

}

#endif // C_FORMS_OPTION_P_H
