/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_BUTTON_H
#define C_BUTTON_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"
#include <QObject>
#include <QUrl>
#include <QtQml/qqmlregistration.h>

namespace CutelystForms {

class ButtonPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Button : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(bool autofocus READ autofocus WRITE setAutofocus)
    Q_PROPERTY(bool disabled READ isDisabled WRITE setDisabled)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(CutelystForms::Button::Type type READ type WRITE setType)
    Q_PROPERTY(QString value READ value WRITE setValue)
    Q_PROPERTY(QString text READ text WRITE setText)
    QML_ELEMENT
public:
    explicit Button(QObject *parent = nullptr);
    virtual ~Button() override;

    enum Type {
        Btn     = 0,
        Submit,
        Reset
    };

    bool autofocus() const;
    void setAutofocus(bool autofocus);

    bool isDisabled() const;
    void setDisabled(bool disabled);

    QString name() const;
    void setName(const QString &name);

    Type type() const;
    void setType(Type type);

    QString value() const;
    void setValue(const QString &value);

    QString text() const;
    void setText(const QString &text);

protected:
    Button(ButtonPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Button)
    Q_DECLARE_PRIVATE(Button)
};

}

#endif // C_BUTTON_H
