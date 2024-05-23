/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_OPTGROUP_H
#define C_FORMS_OPTGROUP_H

#include "cutelyst_plugin_forms_export.h"
#include "option.h"
#include "selectcontent.h"

#include <QCollator>
#include <QQmlListProperty>
#include <QtQml/qqmlregistration.h>

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class OptgroupPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Optgroup : public SelectContent
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CutelystForms::Option> options READ options)
    Q_PROPERTY(QList<CutelystForms::Option *> optionList READ optionList)
    Q_PROPERTY(QMap<QString, CutelystForms::Option *> optionById READ optionIdMap)
    Q_CLASSINFO("DefaultProperty", "options")
    QML_ELEMENT
public:
    explicit Optgroup(QObject *parent = nullptr);
    ~Optgroup() override = default;

    [[nodiscard]] QString name() const noexcept { return {}; }

    [[nodiscard]] QString tagName() const noexcept override;

    QQmlListProperty<CutelystForms::Option> options();
    void appendOption(Option *option);
    void appendOptions(const QList<Option *> &options);
    [[nodiscard]] QList<Option *>::size_type optionCount() const noexcept;
    [[nodiscard]] Option *option(QList<Option *>::size_type idx) const;
    [[nodiscard]] Option *optionById(const QString &id) const;
    void clearOptions();
    void replaceOption(QList<Option *>::size_type idx, Option *o);
    void removeLastOption();
    [[nodiscard]] QList<Option *> optionList() const noexcept;
    [[nodiscard]] QMap<QString, Option *> optionIdMap() const noexcept;

protected:
    Optgroup(OptgroupPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Optgroup)
    Q_DECLARE_PRIVATE(Optgroup) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

class CUTELYST_PLUGIN_FORMS_EXPORT OptgroupCollator : public QCollator
{
public:
    explicit OptgroupCollator(const QLocale &locale)
        : QCollator{locale}
    {
    }

    bool operator()(const Optgroup &left, const Optgroup &right) const
    {
        return compare(left.name(), right.name()) < 0;
    }

    bool operator()(const Optgroup *left, const Optgroup *right) const
    {
        return compare(left->name(), right->name()) < 0;
    }
};

} // namespace CutelystForms

#endif // C_FORMS_OPTGROUP_H
