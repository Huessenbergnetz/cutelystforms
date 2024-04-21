/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMHTMLELEMENT_H
#define C_FORMHTMLELEMENT_H

#include "cutelyst_plugin_forms_export.h"

#include <QObject>
#include <QScopedPointer>
#include <QtQml/qqmlregistration.h>

// clazy:excludeall=qproperty-without-notify

namespace Cutelyst {
class Context;
}

namespace CutelystForms {

class FormHtmlElementPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT FormHtmlElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString accesskey READ accesskey WRITE setAccesskey)
    Q_PROPERTY(QString attrs READ attrs)
    Q_PROPERTY(QString form READ form)
    Q_PROPERTY(bool hidden READ isHidden WRITE setHidden)
    Q_PROPERTY(QString htmlClass READ htmlClass WRITE setHtmlClass)
    Q_PROPERTY(QString htmlId READ htmlId WRITE setHtmlId)
    Q_PROPERTY(bool spellcheck READ spellcheck WRITE setSpellcheck)
    Q_PROPERTY(int tabindex READ tabindex WRITE setTabindex)
    Q_PROPERTY(QString tagName READ tagName CONSTANT)
    Q_PROPERTY(QString title READ title WRITE setTitle)
    QML_ANONYMOUS
public:
    explicit FormHtmlElement(QObject *parent = nullptr);
    ~FormHtmlElement() override;

    Q_REQUIRED_RESULT QString accesskey() const noexcept;
    void setAccesskey(const QString &accesskey) noexcept;

    [[nodiscard]] virtual QString attrs() const;

    [[nodiscard]] QString form() const noexcept;
    void setForm(const QString &form) noexcept;

    Q_REQUIRED_RESULT bool isHidden() const noexcept;
    void setHidden(bool hidden) noexcept;

    Q_REQUIRED_RESULT QString htmlClass() const noexcept;
    void setHtmlClass(const QString &htmlClass) noexcept;

    Q_REQUIRED_RESULT QString htmlId() const noexcept;
    void setHtmlId(const QString &htmlId) noexcept;

    Q_REQUIRED_RESULT bool spellcheck() const noexcept;
    void setSpellcheck(bool spellcheck) noexcept;

    Q_REQUIRED_RESULT int tabindex() const noexcept;
    void setTabindex(int tabindex) noexcept;

    Q_REQUIRED_RESULT virtual QString tagName() const noexcept;

    Q_REQUIRED_RESULT QString title() const noexcept;
    void setTitle(const QString &title) noexcept;

    void setContext(Cutelyst::Context *c);

protected:
    const QScopedPointer<FormHtmlElementPrivate>
        d_ptr; // NOLINT(cppcoreguidelines-non-private-member-variables-in-classes)
    FormHtmlElement(FormHtmlElementPrivate &dd, QObject *parent = nullptr);

    Cutelyst::Context *context() const noexcept;

private:
    Q_DISABLE_COPY(FormHtmlElement)
    Q_DECLARE_PRIVATE(FormHtmlElement) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_FORMHTMLELEMENT_H
