/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_FIELD_H
#define C_FORMS_FIELD_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class FieldPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Field : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString label READ label WRITE setLabel)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    QML_ANONYMOUS
public:
    explicit Field(QObject *parent = nullptr);
    ~Field() override = default;

    Q_REQUIRED_RESULT QString name() const noexcept;
    void setName(const QString &name) noexcept;

    Q_REQUIRED_RESULT QString label() const noexcept;
    void setLabel(const QString &label) noexcept;

    Q_REQUIRED_RESULT QString description() const noexcept;
    void setDescription(const QString &description) noexcept;

protected:
    Field(FieldPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Field)
    Q_DECLARE_PRIVATE(Field) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_FIELD_H
