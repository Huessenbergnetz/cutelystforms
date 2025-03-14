/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "checkboxinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

CheckboxInputPrivate::CheckboxInputPrivate(CheckboxInput *q)
    : FieldPrivate(Field::Checkbox, q)
{
}

QStringList CheckboxInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (checked) {
        lst.append(u"checked"_s);
    }

    return lst;
}

CheckboxInput::CheckboxInput(QObject *parent)
    : Field{*new CheckboxInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type CheckboxInput::type() const noexcept
{
    return Field::Checkbox;
}

QString CheckboxInput::typeString() const noexcept
{
    return u"checkbox"_s;
}

#include "moc_checkboxinput.cpp"
