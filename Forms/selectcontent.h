/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_SELECTCONTENT_H
#define C_FORMS_SELECTCONTENT_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"
#include <QObject>
#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class SelectContentPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT SelectContent : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(bool disabled READ isDisabled WRITE setDisabled)
    Q_PROPERTY(QString label READ label WRITE setLabel)
    QML_ANONYMOUS
public:
    explicit SelectContent(QObject *parent = nullptr);
    virtual ~SelectContent() override;

    bool isDisabled() const;
    void setDisabled(bool disabled);

    QString label() const;
    void setLabel(const QString &label);

protected:
    SelectContent(SelectContentPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(SelectContent)
    Q_DECLARE_PRIVATE(SelectContent)
};

}

#endif // C_FORMS_SELECTCONTENT_H
