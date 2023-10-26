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
    QMap<QString, Field *> fieldIdMap;
    QMap<QString, Field *> fieldNameMap;
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

    static void appendField(QQmlListProperty<Field>*, Field*);
    static QList<Field*>::size_type fieldCount(QQmlListProperty<Field>*);
    static Field* field(QQmlListProperty<Field>*, QList<Field*>::size_type);
    static void clearFields(QQmlListProperty<Field>*);
    static void replaceField(QQmlListProperty<Field>*, QList<Field*>::size_type, Field*);
    static void removeLastField(QQmlListProperty<Field>*);

private:
    Q_DECLARE_PUBLIC(Form) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(FormPrivate)
};

}

#endif // C_FORM_P_H
