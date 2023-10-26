/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_LEGEND_H
#define C_LEGEND_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"
#include <QObject>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class LegendPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Legend : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    QML_ELEMENT
public:
    explicit Legend(QObject *parent = nullptr);
    ~Legend() override = default;

    Q_REQUIRED_RESULT QString text() const noexcept;
    void setText(const QString &text) noexcept;

protected:
    Legend(LegendPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Legend)
    Q_DECLARE_PRIVATE(Legend) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_LEGEND_H
