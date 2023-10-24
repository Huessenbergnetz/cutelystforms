/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_FIELD_H
#define C_FORMS_FIELD_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"
#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class FieldPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Field : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(CutelystForms::Field::Type type READ type WRITE setType)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString label READ label WRITE setLabel)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(int colspan READ colspan WRITE setColspan)
    QML_ELEMENT
public:
    explicit Field(QObject *parent = nullptr);
    virtual ~Field() override;

    enum Type {
        Text            = 0,
        Search,
        Password,
        Tel,
        Url,
        Email,
        Number,
        Range,
        Radio,
        Checkbox,
        Hidden,
        File,
        Color,
        Date,
        DatetimeLocal,
        Week,
        Month,
        Time,
        Select,
        Textarea
    };
    Q_ENUM(Type)

    Field::Type type() const;
    void setType(Field::Type type);

    QString name() const;
    void setName(const QString &name);

    QString label() const;
    void setLabel(const QString &label);

    QString description() const;
    void setDescription(const QString &description);

    int colspan() const;
    void setColspan(int colspan);

protected:
    Field(FieldPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Field)
    Q_DECLARE_PRIVATE(Field)
};

}

#endif // C_FORMS_FIELD_H
