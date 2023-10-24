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
    virtual ~Optgroup() override;

    QQmlListProperty<CutelystForms::Option> options();
    void appendOption(Option *option);
    QList<Option*>::size_type optionCount() const;
    Option *option(QList<Option*>::size_type idx) const;
    void clearOptions();
    QList<Option*> optionList() const;

protected:
    Optgroup(OptgroupPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Optgroup)
    Q_DECLARE_PRIVATE(Optgroup)
};

}

#endif // C_FORMS_OPTGROUP_H
