/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_LEGEND_H
#define C_LEGEND_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"

#include <QtQml/qqmlregistration.h>

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class LegendPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Legend : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    QML_NAMED_ELEMENT(FormLegend)
public:
    explicit Legend(QObject *parent = nullptr);
    ~Legend() override = default;

    Q_REQUIRED_RESULT QString text() const noexcept;
    void setText(const QString &text) noexcept;

    Q_REQUIRED_RESULT QString tagName() const noexcept override;

protected:
    Legend(LegendPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Legend)
    Q_DECLARE_PRIVATE(Legend) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_LEGEND_H
