/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_BUTTON_H
#define C_BUTTON_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"

#include <QUrl>
#include <QVariant>
#include <QtQml/qqmlregistration.h>

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class ButtonPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Button : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(bool disabled READ isDisabled WRITE setDisabled)
    Q_PROPERTY(QUrl formaction READ formaction WRITE setFormaction)
    Q_PROPERTY(CutelystForms::Button::EncType formenctype READ formenctype WRITE setFormenctype)
    Q_PROPERTY(QString formenctypeString READ formenctypeString)
    Q_PROPERTY(CutelystForms::Button::Method formmethod READ formmethod WRITE setFormmethod)
    Q_PROPERTY(QString formmethodString READ formmethodString)
    Q_PROPERTY(bool formnovalidate READ formnovalidate WRITE setFormnovalidate)
    Q_PROPERTY(CutelystForms::Button::Target formtarget READ formtarget WRITE setFormtarget)
    Q_PROPERTY(QString formtargetString READ formtargetString)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(CutelystForms::Button::Type type READ type WRITE setType)
    Q_PROPERTY(QString typeString READ typeString)
    Q_PROPERTY(QVariant value READ value WRITE setValue)
    QML_NAMED_ELEMENT(FormButton)
public:
    explicit Button(QObject *parent = nullptr);
    ~Button() override = default;

    enum Type { Btn = 0, Submit, Reset };
    Q_ENUM(Type)

    enum EncType { NoEncType = 0, WwwFormUrlEncoded, MultipartFormData, TextPlain };
    Q_ENUM(EncType)

    enum Method { NoMethod = 0, Post, Get };
    Q_ENUM(Method)

    enum Target { NoTarget = 0, Self, Blank, Parent, Top };
    Q_ENUM(Target)

    Q_REQUIRED_RESULT bool isDisabled() const noexcept;
    void setDisabled(bool disabled) noexcept;

    [[nodiscard]] QUrl formaction() const noexcept;
    void setFormaction(const QUrl &formaction) noexcept;

    [[nodiscard]] EncType formenctype() const noexcept;
    void setFormenctype(EncType formenctype) noexcept;
    [[nodiscard]] QString formenctypeString() const;

    [[nodiscard]] Method formmethod() const noexcept;
    void setFormmethod(Method formmethod) noexcept;
    [[nodiscard]] QString formmethodString() const;

    [[nodiscard]] bool formnovalidate() const noexcept;
    void setFormnovalidate(bool formnovalidate) noexcept;

    [[nodiscard]] Target formtarget() const noexcept;
    void setFormtarget(Target formtarget) noexcept;
    [[nodiscard]] QString formtargetString() const;

    Q_REQUIRED_RESULT QString name() const noexcept;
    void setName(const QString &name) noexcept;

    Q_REQUIRED_RESULT QString tagName() const noexcept override;

    Q_REQUIRED_RESULT QString text() const noexcept;
    void setText(const QString &text) noexcept;

    Q_REQUIRED_RESULT Type type() const noexcept;
    void setType(Type type) noexcept;
    [[nodiscard]] QString typeString() const;

    Q_REQUIRED_RESULT QVariant value() const noexcept;
    void setValue(const QVariant &value) noexcept;

protected:
    Button(ButtonPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Button)
    Q_DECLARE_PRIVATE(Button) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_BUTTON_H
