/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_LEGEND_H
#define C_LEGEND_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"
#include <QObject>
#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class LegendPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Legend : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    QML_ELEMENT
public:
    explicit Legend(QObject *parent = nullptr);
    virtual ~Legend() override;

    QString text() const;
    void setText(const QString &text);

protected:
    Legend(LegendPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Legend)
    Q_DECLARE_PRIVATE(Legend)
};

}

#endif // C_LEGEND_H
