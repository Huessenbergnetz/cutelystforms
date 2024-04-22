/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "monthinput_p.h"

using namespace CutelystForms;

MonthInputPrivate::MonthInputPrivate(MonthInput *q)
    : FieldPrivate{Field::Month, q}
{
}

QString MonthInputPrivate::getMonthString(const QVariant &v) const
{
    if (v.userType() == QMetaType::QDate) {
        return v.toDate().toString(u"yyyy-MM");
    } else if (v.userType() == QMetaType::QDateTime) {
        return convertedDateTime(v.toDateTime()).date().toString(u"yyyy-MM");
    }

    return v.toString();
}

QStringList MonthInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (!list.isEmpty()) {
        lst.append(u"list=\""_qs + list + QLatin1Char('"'));
    }

    if (!max.isNull()) {
        lst.append(u"max=\""_qs + getMonthString(max) + QLatin1Char('"'));
    }

    if (!min.isNull()) {
        lst.append(u"min=\""_qs + getMonthString(min) + QLatin1Char('"'));
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

QString MonthInputPrivate::getValueString() const
{
    return getMonthString(value);
}

MonthInput::MonthInput(QObject *parent)
    : Field{*new MonthInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type MonthInput::type() const noexcept
{
    return Field::Month;
}

QString MonthInput::typeString() const noexcept
{
    return QStringLiteral("month");
}

#include "moc_monthinput.cpp"
