/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "timeinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

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
        lst.append(u"list=\""_s + list + '"'_L1);
    }

    if (!max.isNull()) {
        lst.append(u"max=\""_s + getTimeString(max) + '"'_L1);
    }

    if (!min.isNull()) {
        lst.append(u"min=\""_s + getTimeString(min) + '"'_L1);
    }

    if (!step.isNull()) {
        const auto stepInt = step.toInt();
        if (stepInt > 0) {
            lst.append(u"step=\""_s + QString::number(stepInt) + '"'_L1);
        }
    }

    if (readonly) {
        lst.append(u"readonly"_s);
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
    return u"time"_s;
}

#include "moc_timeinput.cpp"
