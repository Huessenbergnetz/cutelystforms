/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "weekinput_p.h"

using namespace CutelystForms;

WeekInputPrivate::WeekInputPrivate(WeekInput *q)
    : FieldPrivate{Field::Week, q}
{
}

QString WeekInputPrivate::getWeekString(const QVariant &v) const
{
    QDate date;
    if (v.userType() == QMetaType::QDate) {
        date = v.toDate();
    } else if (v.userType() == QMetaType::QDateTime) {
        date = convertedDateTime(v.toDateTime()).date();
    }

    if (date.isValid()) {
        int yearNumber{date.year()};
        int weekNumber = date.weekNumber(&yearNumber);
        return QString::number(yearNumber) + u"-W" +
               QString::number(weekNumber).rightJustified(2, u'0');
    }

    return v.toString();
}

QStringList WeekInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (!list.isEmpty()) {
        lst.append(u"list=\""_qs + list + QLatin1Char('"'));
    }

    if (!max.isNull()) {
        lst.append(u"max=\""_qs + getWeekString(max) + QLatin1Char('"'));
    }

    if (!min.isNull()) {
        lst.append(u"min=\""_qs + getWeekString(min) + QLatin1Char('"'));
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

QString WeekInputPrivate::getValueString() const
{
    return getWeekString(value);
}

WeekInput::WeekInput(QObject *parent)
    : Field{*new WeekInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type WeekInput::type() const noexcept
{
    return Field::Week;
}

QString WeekInput::typeString() const noexcept
{
    return QStringLiteral("week");
}

#include "moc_weekinput.cpp"
