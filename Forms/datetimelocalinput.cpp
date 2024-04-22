/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "datetimelocalinput_p.h"

using namespace CutelystForms;

DateTimeLocalInputPrivate::DateTimeLocalInputPrivate(DateTimeLocalInput *q)
    : FieldPrivate{Field::DateTimeLocal, q}
{
}

QString DateTimeLocalInputPrivate::getDateTimeString(const QVariant &v) const
{
    if (v.userType() == QMetaType::QDateTime || v.userType() == QMetaType::QDate) {
        return convertedDateTime(v.toDateTime()).toString(u"yyyy-MM-ddTHH:mm:ss");
    }

    return v.toString();
}

QStringList DateTimeLocalInputPrivate::attrList() const
{
    QStringList lst = FieldPrivate::attrList();

    if (!list.isEmpty()) {
        lst.append(u"list=\""_qs + list + QLatin1Char('"'));
    }

    if (!max.isNull()) {
        lst.append(u"max=\""_qs + getDateTimeString(max) + QLatin1Char('"'));
    }

    if (!min.isNull()) {
        lst.append(u"min=\""_qs + getDateTimeString(min) + QLatin1Char('"'));
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

QString DateTimeLocalInputPrivate::getValueString() const
{
    return getDateTimeString(value);
}

DateTimeLocalInput::DateTimeLocalInput(QObject *parent)
    : Field{*new DateTimeLocalInputPrivate{this}, parent}
{
}

CutelystForms::Field::Type DateTimeLocalInput::type() const noexcept
{
    return Field::DateTimeLocal;
}

QString DateTimeLocalInput::typeString() const noexcept
{
    return QStringLiteral("datetime-local");
}

#include "moc_datetimelocalinput.cpp"
