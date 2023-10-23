/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_SELECTCONTENT_P_H
#define C_FORMS_SELECTCONTENT_P_H

#include "selectcontent.h"
#include "formhtmlelement_p.h"

namespace CutelystForms {

class SelectContentPrivate : public FormHtmlElementPrivate
{
public:
    SelectContentPrivate(SelectContent *q);

    QString label;
    bool disabled;

private:
    Q_DECLARE_PUBLIC(SelectContent)
    Q_DISABLE_COPY(SelectContentPrivate)
};

}

#endif // C_FORMS_SELECTCONTENT_P_H
