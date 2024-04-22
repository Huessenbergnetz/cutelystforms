/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "dateinput_p.h"

using namespace CutelystForms;

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
        lst.append(u"list=\""_qs + list + QLatin1Char('"'));
    }

    if (!max.isNull()) {
        lst.append(u"max=\""_qs + getDateString(max) + QLatin1Char('"'));
    }

    if (!min.isNull()) {
        lst.append(u"min=\""_qs + getDateString(min) + QLatin1Char('"'));
    }

    if (!step.isNull()) {
        const auto stepInt = step.toInt();
        if (stepInt > 1) {
            lst.append(u"step=\""_qs + QString::number(stepInt) + QLatin1Char('"'));
        }
    }

    if (readonly) {
        lst.append(u"readonly"_qs);
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
    return QStringLiteral("date");
}

#include "moc_dateinput.cpp"
