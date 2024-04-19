/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORM_P_H
#define C_FORM_P_H

#include "form.h"
#include "formhtmlelement_p.h"
#include "namedlistproperty_p.h"

namespace CutelystForms {

class FormPrivate : public FormHtmlElementPrivate
{
public:
    FormPrivate(Form *q);
    ~FormPrivate() override = default;

    NamedListProperty<Field, Form> fields;
    NamedListProperty<Fieldset, Form> fieldsets;
    NamedListProperty<Button, Form> buttons;
    QUrl action;
    QStringList acceptCharset;
    QString description;
    QString label;
    QString name;
    Form::EncType enctype{Form::WwwFormUrlEncoded};
    Form::Method method{Form::Get};
    Form::Target target{Form::Self};
    bool autocomplete{true};
    bool novalidate{false};

    C_FORMS_QMLLIST_FUNCS(Field, field, Form);
    C_FORMS_QMLLIST_FUNCS(Fieldset, fieldset, Form)
    C_FORMS_QMLLIST_FUNCS(Button, button, Form)

    virtual QStringList attrList() const override;
    QString enctypeString() const;
    QString methodString() const;
    QString targetString() const;

private:
    Q_DECLARE_PUBLIC(Form) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(FormPrivate)
};

}

#endif // C_FORM_P_H
