/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_FIELDSET_P_H
#define C_FORMS_FIELDSET_P_H

#include "fieldset.h"
#include "formhtmlelement_p.h"

namespace CutelystForms {

class FieldsetPrivate : public FormHtmlElementPrivate
{
public:
    FieldsetPrivate(Fieldset *q);
    ~FieldsetPrivate() override = default;

    QList<Field*> fields;
    QString form;
    QString name;
    QString label;
    QString description;
    Legend *legend{nullptr};
    bool disabled{false};

private:
    Q_DECLARE_PUBLIC(Fieldset) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(FieldsetPrivate)
};

}

#endif // C_FORMS_FIELDSET_P_H
