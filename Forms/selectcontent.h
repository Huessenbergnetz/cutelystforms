/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_SELECTCONTENT_H
#define C_FORMS_SELECTCONTENT_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"

#include <QtQml/qqmlregistration.h>

// clazy:excludeall=qproperty-without-notify

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
    ~SelectContent() override = default;

    Q_REQUIRED_RESULT bool isDisabled() const noexcept;
    void setDisabled(bool disabled) noexcept;

    Q_REQUIRED_RESULT QString label() const noexcept;
    void setLabel(const QString &label) noexcept;

protected:
    SelectContent(SelectContentPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(SelectContent)
    Q_DECLARE_PRIVATE(SelectContent) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

} // namespace CutelystForms

#endif // C_FORMS_SELECTCONTENT_H
