/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_OPTGROUP_H
#define C_FORMS_OPTGROUP_H

#include "cutelyst_plugin_forms_export.h"
#include "selectcontent.h"
#include "option.h"
#include <QObject>
#include <QQmlListProperty>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class OptgroupPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Optgroup : public SelectContent
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CutelystForms::Option> options READ options)
    Q_PROPERTY(QList<CutelystForms::Option*> optionList READ optionList)
    Q_PROPERTY(QMap<QString, CutelystForms::Option*> optionById READ optionIdMap)
    Q_CLASSINFO("DefaultProperty", "options")
    QML_ELEMENT
public:
    explicit Optgroup(QObject *parent = nullptr);
    ~Optgroup() override = default;

    Q_REQUIRED_RESULT QString name() const noexcept
    { return {}; }

    Q_REQUIRED_RESULT QString tagName() const noexcept override;

    QQmlListProperty<CutelystForms::Option> options();
    void appendOption(Option *option);
    Q_REQUIRED_RESULT QList<Option*>::size_type optionCount() const noexcept;
    Q_REQUIRED_RESULT Option *option(QList<Option*>::size_type idx) const;
    Q_REQUIRED_RESULT Option *optionById(const QString &id) const;
    void clearOptions();
    void replaceOption(QList<Option*>::size_type idx, Option *o);
    void removeLastOption();
    Q_REQUIRED_RESULT QList<Option*> optionList() const noexcept;
    Q_REQUIRED_RESULT QMap<QString, Option*> optionIdMap() const noexcept;

protected:
    Optgroup(OptgroupPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Optgroup)
    Q_DECLARE_PRIVATE(Optgroup) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_OPTGROUP_H
