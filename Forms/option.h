/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_OPTION_H
#define C_FORMS_OPTION_H

#include "cutelyst_plugin_forms_export.h"
#include "selectcontent.h"

#include <QCollator>
#include <QtQml/qqmlregistration.h>

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
    Option(const QString &text,
           const QString &value,
           bool selected   = false,
           QObject *parent = nullptr);
    Option(const QString &textAndValue, bool selected = false, QObject *parent = nullptr);
    ~Option() override = default;

    [[nodiscard]] bool isSelected() const noexcept;
    void setSelected(bool selected) noexcept;

    [[nodiscard]] QString text() const noexcept;
    void setText(const QString &text) noexcept;

    [[nodiscard]] QString value() const noexcept;
    void setValue(const QString &value) noexcept;

    [[nodiscard]] QString tagName() const noexcept override;

    [[nodiscard]] QString name() const noexcept { return {}; }

protected:
    Option(OptionPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Option)
    Q_DECLARE_PRIVATE(Option) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

class CUTELYST_PLUGIN_FORMS_EXPORT OptionCollator : public QCollator
{
public:
    explicit OptionCollator(const QLocale &locale)
        : QCollator{locale}
    {
    }

    bool operator()(const Option &left, const Option &right) const
    {
        return compare(left.text(), right.text());
    }

    bool operator()(const Option *left, const Option *right) const
    {
        return compare(left->text(), right->text());
    }
};

} // namespace CutelystForms

#endif // C_FORMS_OPTION_H
