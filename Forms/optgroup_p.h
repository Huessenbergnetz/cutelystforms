/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_OPTGROUP_P_H
#define C_FORMS_OPTGROUP_P_H

#include "namedlistproperty_p.h"
#include "optgroup.h"
#include "selectcontent_p.h"

namespace CutelystForms {

class OptgroupPrivate : public SelectContentPrivate
{
public:
    explicit OptgroupPrivate(Optgroup *q);
    OptgroupPrivate(const QString &_label, Optgroup *q);
    ~OptgroupPrivate() override = default;

    NamedListProperty<Option, Optgroup> options;

    C_FORMS_QMLLIST_FUNCS(Option, option, Optgroup)

private:
    Q_DECLARE_PUBLIC(Optgroup) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(OptgroupPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_OPTGROUP_P_H
