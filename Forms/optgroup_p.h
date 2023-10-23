/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_OPTGROUP_P_H
#define C_FORMS_OPTGROUP_P_H

#include "optgroup.h"
#include "selectcontent_p.h"

namespace CutelystForms {

class OptgroupPrivate : public SelectContentPrivate
{
public:
    OptgroupPrivate(Optgroup *q);

    QList<Option*> options;

private:
    Q_DECLARE_PUBLIC(Optgroup)
    Q_DISABLE_COPY(OptgroupPrivate)
};

}

#endif // C_FORMS_OPTGROUP_P_H
