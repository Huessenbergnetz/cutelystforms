/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "dateinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

DateInputPrivate::DateInputPrivate(DateInput *q)
    : FieldPrivate{Field::Date, q}
{
}

QString DateInputPrivate::getDateString(const QVariant &v) const
{
    if (v.userType() == QMetaType::QDate) {
        return v.toDate().toString(Qt::ISODate);
    } else if (v.userType() == QMetaType::QDateTime) {
        return convertedDateTime(v.toDateTime()).date().toString(Qt::ISODate);
    }

    return v.toString();
}

QStringList DateInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (!list.isEmpty()) {
        lst.append(u"list=\""_s + list + '"'_L1);
    }

    if (!max.isNull()) {
        lst.append(u"max=\""_s + getDateString(max) + '"'_L1);
    }

    if (!min.isNull()) {
        lst.append(u"min=\""_s + getDateString(min) + '"'_L1);
    }

    if (!step.isNull()) {
        const auto stepInt = step.toInt();
        if (stepInt > 1) {
            lst.append(u"step=\""_s + QString::number(stepInt) + '"'_L1);
        }
    }

    if (readonly) {
        lst.append(u"readonly"_s);
    }

    return lst;
}

QString DateInputPrivate::getValueString() const
{
    return getDateString(value);
}

DateInput::DateInput(QObject *parent)
    : Field{*new DateInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type DateInput::type() const noexcept
{
    return Field::Date;
}

QString DateInput::typeString() const noexcept
{
    return u"date"_s;
}

#include "moc_dateinput.cpp"
