/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_FIELD_P_H
#define C_FORMS_FIELD_P_H

#include "field.h"
#include "formhtmlelement_p.h"
#include "namedlistproperty_p.h"

namespace CutelystForms {

class FieldPrivate : public FormHtmlElementPrivate
{
public:
    FieldPrivate(Field::Type _type, Field *q);
    ~FieldPrivate() override = default;

    virtual QStringList attrList() const override;

    NamedListProperty<Option, Field> options;
    NamedListProperty<Optgroup, Field> optgroups;
    QVariant value;
    QString accept;
    QString autocomplete;
    QString description;
    QString label;
    QString name;
    Field::Type type{Field::None};
    bool checked{false};
    bool disabled{false};
    bool multiple{false};
    bool required{false};

    C_FORMS_QMLLIST_FUNCS(Option, option, Field)
    C_FORMS_QMLLIST_FUNCS(Optgroup, optgroup, Field)

private:
    Q_DECLARE_PUBLIC(Field) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(FieldPrivate)
};

}

#endif // C_FORMS_FIELD_P_H
