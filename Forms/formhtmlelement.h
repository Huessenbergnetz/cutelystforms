/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMHTMLELEMENT_H
#define C_FORMHTMLELEMENT_H

#include "cutelyst_plugin_forms_export.h"
#include <QObject>
#include <QScopedPointer>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class FormHtmlElementPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT FormHtmlElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString htmlId READ htmlId WRITE setHtmlId)
    Q_PROPERTY(QString htmlClass READ htmlClass WRITE setHtmlClass)
    Q_PROPERTY(QString accesskey READ accesskey WRITE setAccesskey)
    Q_PROPERTY(bool contenteditable READ isContenteditable WRITE setContenteditable)
    Q_PROPERTY(QString contextmenu READ contextmenu WRITE setContextmenu)
    Q_PROPERTY(CutelystForms::FormHtmlElement::TextDirection dir READ dir WRITE setDir)
    Q_PROPERTY(CutelystForms::FormHtmlElement::DraggableState draggable READ draggable WRITE setDraggable)
    Q_PROPERTY(bool hidden READ isHidden WRITE setHidden)
    Q_PROPERTY(QString lang READ lang WRITE setLang)
    Q_PROPERTY(bool spellcheck READ spellcheck WRITE setSpellcheck)
    Q_PROPERTY(QString style READ style WRITE setStyle)
    Q_PROPERTY(int tabindex READ tabindex WRITE setTabindex)
    Q_PROPERTY(QString title READ title WRITE setTitle)
    QML_ANONYMOUS
public:
    explicit FormHtmlElement(QObject *parent = nullptr);
    ~FormHtmlElement() override;

    enum TextDirection {
        AutoDir = 0,
        Ltr,
        Rtl
    };
    Q_ENUM(TextDirection)

    enum DraggableState {
        DragAuto    = 0,
        DragTrue,
        DragFalse
    };
    Q_ENUM(DraggableState)

    Q_REQUIRED_RESULT QString htmlId() const noexcept;
    void setHtmlId(const QString &htmlId) noexcept;

    Q_REQUIRED_RESULT QString htmlClass() const noexcept;
    void setHtmlClass(const QString &htmlClass) noexcept;

    Q_REQUIRED_RESULT QString accesskey() const noexcept;
    void setAccesskey(const QString &accesskey) noexcept;

    Q_REQUIRED_RESULT bool isContenteditable() const noexcept;
    void setContenteditable(bool contenteditable) noexcept;

    Q_REQUIRED_RESULT QString contextmenu() const noexcept;
    void setContextmenu(const QString &contextmenu) noexcept;

    Q_REQUIRED_RESULT TextDirection dir() const noexcept;
    void setDir(TextDirection dir) noexcept;

    Q_REQUIRED_RESULT DraggableState draggable() const noexcept;
    void setDraggable(DraggableState draggable) noexcept;

    Q_REQUIRED_RESULT bool isHidden() const noexcept;
    void setHidden(bool hidden) noexcept;

    Q_REQUIRED_RESULT QString lang() const noexcept;
    void setLang(const QString &lang) noexcept;

    Q_REQUIRED_RESULT bool spellcheck() const noexcept;
    void setSpellcheck(bool spellcheck) noexcept;

    Q_REQUIRED_RESULT QString style() const noexcept;
    void setStyle(const QString &style) noexcept;

    Q_REQUIRED_RESULT int tabindex() const noexcept;
    void setTabindex(int tabindex) noexcept;

    Q_REQUIRED_RESULT QString title() const noexcept;
    void setTitle(const QString &title) noexcept;

protected:
    const QScopedPointer<FormHtmlElementPrivate> d_ptr; // NOLINT(cppcoreguidelines-non-private-member-variables-in-classes)
    FormHtmlElement(FormHtmlElementPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(FormHtmlElement)
    Q_DECLARE_PRIVATE(FormHtmlElement) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMHTMLELEMENT_H
