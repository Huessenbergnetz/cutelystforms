/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
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
    Q_CLASSINFO("DefaultProperty", "options")
    QML_ELEMENT
public:
    explicit Optgroup(QObject *parent = nullptr);
    ~Optgroup() override = default;

    QQmlListProperty<CutelystForms::Option> options();
    void appendOption(Option *option);
    Q_REQUIRED_RESULT QList<Option*>::size_type optionCount() const;
    Q_REQUIRED_RESULT Option *option(QList<Option*>::size_type idx) const;
    void clearOptions();
    Q_REQUIRED_RESULT QList<Option*> optionList() const noexcept;

protected:
    Optgroup(OptgroupPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Optgroup)
    Q_DECLARE_PRIVATE(Optgroup) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_OPTGROUP_H
