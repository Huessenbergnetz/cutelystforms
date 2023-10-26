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
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

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
    ~Button() override = default;

    enum Type {
        Btn     = 0,
        Submit,
        Reset
    };
    Q_ENUM(Type)

    Q_REQUIRED_RESULT bool autofocus() const noexcept;
    void setAutofocus(bool autofocus) noexcept;

    Q_REQUIRED_RESULT bool isDisabled() const noexcept;
    void setDisabled(bool disabled) noexcept;

    Q_REQUIRED_RESULT QString name() const noexcept;
    void setName(const QString &name) noexcept;

    Q_REQUIRED_RESULT Type type() const noexcept;
    void setType(Type type) noexcept;

    Q_REQUIRED_RESULT QString value() const noexcept;
    void setValue(const QString &value) noexcept;

    Q_REQUIRED_RESULT QString text() const noexcept;
    void setText(const QString &text) noexcept;

protected:
    Button(ButtonPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Button)
    Q_DECLARE_PRIVATE(Button) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_BUTTON_H
