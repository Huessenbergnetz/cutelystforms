/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "weekinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

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
        lst.append(u"list=\""_s + list + '"'_L1);
    }

    if (!max.isNull()) {
        lst.append(u"max=\""_s + getWeekString(max) + '"'_L1);
    }

    if (!min.isNull()) {
        lst.append(u"min=\""_s + getWeekString(min) + '"'_L1);
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
    return u"week"_s;
}

#include "moc_weekinput.cpp"
