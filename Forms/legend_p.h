/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_LEGEND_P_H
#define C_LEGEND_P_H

#include "legend.h"
#include "formhtmlelement_p.h"

namespace CutelystForms {

class LegendPrivate : FormHtmlElementPrivate
{
public:
    LegendPrivate(Legend *q);

    QString text;

private:
    Q_DECLARE_PUBLIC(Legend)
    Q_DISABLE_COPY(LegendPrivate)
};

}

#endif // C_LEGEND_P_H
