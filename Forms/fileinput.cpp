/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fileinput_p.h"

using namespace CutelystForms;

FileInputPrivate::FileInputPrivate(FileInput *q)
    : FieldPrivate(Field::File, q)
{
}

QStringList FileInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (!accept.isEmpty()) {
        lst.append(u"accept=\""_qs + accept + QLatin1Char('"'));
    }

    if (multiple) {
        lst.append(u"multiple"_qs);
    }

    return lst;
}

FileInput::FileInput(QObject *parent)
    : Field{*new FileInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type FileInput::type() const noexcept
{
    return Field::File;
}

QString FileInput::typeString() const noexcept
{
    return QStringLiteral("file");
}

#include "moc_fileinput.cpp"
