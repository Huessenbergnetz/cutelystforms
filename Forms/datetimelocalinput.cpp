/*!
 * SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "datetimelocalinput_p.h"

using namespace CutelystForms;
using namespace Qt::Literals::StringLiterals;

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
        lst.append(u"list=\""_s + list + '"'_L1);
    }

    if (!max.isNull()) {
        lst.append(u"max=\""_s + getDateTimeString(max) + '"'_L1);
    }

    if (!min.isNull()) {
        lst.append(u"min=\""_s + getDateTimeString(min) + '"'_L1);
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
    return u"datetime-local"_s;
}

#include "moc_datetimelocalinput.cpp"
