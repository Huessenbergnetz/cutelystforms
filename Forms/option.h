/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_OPTION_H
#define C_FORMS_OPTION_H

#include "cutelyst_plugin_forms_export.h"
#include "selectcontent.h"
#include <QObject>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class OptionPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Option : public SelectContent
{
    Q_OBJECT
    Q_PROPERTY(bool selected READ isSelected WRITE setSelected)
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(QString value READ value WRITE setValue)
    QML_ELEMENT
public:
    explicit Option(QObject *parent = nullptr);
    ~Option() override = default;

    Q_REQUIRED_RESULT bool isSelected() const noexcept;
    void setSelected(bool selected) noexcept;

    Q_REQUIRED_RESULT QString text() const noexcept;
    void setText(const QString &text) noexcept;

    Q_REQUIRED_RESULT QString value() const noexcept;
    void setValue(const QString &value) noexcept;

    Q_REQUIRED_RESULT QString tagName() const noexcept override;

    Q_REQUIRED_RESULT QString name() const noexcept
    { return {}; }

protected:
    Option(OptionPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Option)
    Q_DECLARE_PRIVATE(Option) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_OPTION_H
