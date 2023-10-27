/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_OPTGROUP_P_H
#define C_FORMS_OPTGROUP_P_H

#include "optgroup.h"
#include "selectcontent_p.h"
#include "namedlistproperty_p.h"

namespace CutelystForms {

class OptgroupPrivate : public SelectContentPrivate
{
public:
    OptgroupPrivate(Optgroup *q);
    ~OptgroupPrivate() override = default;

    NamedListProperty<Option, Optgroup> options;

    C_FORMS_QMLLIST_FUNCS(Option, option, Optgroup)

private:
    Q_DECLARE_PUBLIC(Optgroup) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(OptgroupPrivate)
};

}

#endif // C_FORMS_OPTGROUP_P_H
