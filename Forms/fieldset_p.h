/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_FIELDSET_P_H
#define C_FORMS_FIELDSET_P_H

#include "fieldset.h"
#include "formhtmlelement_p.h"
#include "namedlistproperty_p.h"

namespace CutelystForms {

class FieldsetPrivate : public FormHtmlElementPrivate
{
public:
    FieldsetPrivate(Fieldset *q);
    ~FieldsetPrivate() override = default;

    virtual QStringList attrList() const override;

    NamedListProperty<Field, Fieldset> fields;
    QString form;
    QString name;
    QString label;
    QString legend;
    QString description;
    bool disabled{false};

    C_FORMS_QMLLIST_FUNCS(Field, field, Fieldset)

private:
    Q_DECLARE_PUBLIC(Fieldset) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(FieldsetPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_FIELDSET_P_H
