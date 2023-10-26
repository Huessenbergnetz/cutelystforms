/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORM_P_H
#define C_FORM_P_H

#include "form.h"
#include "formhtmlelement_p.h"

namespace CutelystForms {

class FormPrivate : public FormHtmlElementPrivate
{
public:
    FormPrivate(Form *q);
    ~FormPrivate() override = default;

    QList<Field *> fields;
    QList<Fieldset *> fieldsets;
    QList<Button *> buttons;
    QUrl action;
    QStringList acceptCharset;
    QString name;
    QString label;
    QString description;
    Form::EncType enctype{Form::WwwFormUrlEncoded};
    Form::Method method{Form::Get};
    Form::Target target{Form::Self};
    Form::Type type{Form::Vertical};
    bool autocomplete{true};
    bool novalidate{false};

private:
    Q_DECLARE_PUBLIC(Form) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(FormPrivate)
};

}

#endif // C_FORM_P_H
