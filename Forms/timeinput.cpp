/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "timeinput_p.h"

using namespace CutelystForms;

TimeInputPrivate::TimeInputPrivate(TimeInput *q)
    : FieldPrivate{Field::Time, q}
{
}

QString TimeInputPrivate::getTimeString(const QVariant &v) const
{
    if (v.userType() == QMetaType::QTime) {
        return v.toTime().toString(u"HH:mm:ss");
    } else if (v.userType() == QMetaType::QDateTime) {
        return convertedDateTime(v.toDateTime()).time().toString(u"HH:mm:ss");
    }

    return v.toString();
}

QStringList TimeInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (!list.isEmpty()) {
        lst.append(u"list=\""_qs + list + QLatin1Char('"'));
    }

    if (!max.isNull()) {
        lst.append(u"max=\""_qs + getTimeString(max) + QLatin1Char('"'));
    }

    if (!min.isNull()) {
        lst.append(u"min=\""_qs + getTimeString(min) + QLatin1Char('"'));
    }

    if (!step.isNull()) {
        const auto stepInt = step.toInt();
        if (stepInt > 0) {
            lst.append(u"step=\""_qs + QString::number(stepInt) + QLatin1Char('"'));
        }
    }

    if (readonly) {
        lst.append(u"readonly"_qs);
    }

    return lst;
}

QString TimeInputPrivate::getValueString() const
{
    return getTimeString(value);
}

TimeInput::TimeInput(QObject *parent)
    : Field{*new TimeInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type TimeInput::type() const noexcept
{
    return Field::Time;
}

QString TimeInput::typeString() const noexcept
{
    return QStringLiteral("time");
}

#include "moc_timeinput.cpp"
