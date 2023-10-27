/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_SELECT_H
#define C_FORMS_SELECT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"
#include "option.h"
#include "optgroup.h"
#include <QObject>
#include <QQmlListProperty>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class SelectPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Select : public Field
{
    Q_OBJECT
    Q_PROPERTY(bool multiple READ multiple WRITE setMultiple)
    Q_PROPERTY(int size READ size WRITE setSize)
    Q_PROPERTY(QQmlListProperty<CutelystForms::Option> options READ options)
    Q_PROPERTY(QMap<QString, CutelystForms::Option*> optionById READ optionIdMap)
    Q_PROPERTY(QQmlListProperty<CutelystForms::Optgroup> optgroups READ optgroups)
    Q_PROPERTY(QMap<QString, CutelystForms::Optgroup*> optgroupById READ optgroupIdMap)
    Q_CLASSINFO("DefaultProperty", "options")
    QML_ELEMENT
public:
    explicit Select(QObject *parent = nullptr);
    ~Select() override = default;

    Q_REQUIRED_RESULT bool multiple() const noexcept;
    void setMultiple(bool multiple) noexcept;

    Q_REQUIRED_RESULT int size() const noexcept;
    void setSize(int size) noexcept;

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

    QQmlListProperty<CutelystForms::Optgroup> optgroups();
    void appendOptgroup(Optgroup *optgroup);
    Q_REQUIRED_RESULT QList<Optgroup*>::size_type optgroupCount() const noexcept;
    Q_REQUIRED_RESULT Optgroup *optgroup(QList<Optgroup*>::size_type idx) const;
    Q_REQUIRED_RESULT Optgroup *optgroupById(const QString &id) const;
    void clearOptgroups();
    void replaceOptgroup(QList<Optgroup*>::size_type idx, Optgroup *o);
    void removeLastOptgroup();
    Q_REQUIRED_RESULT QList<Optgroup*> optgroupList() const noexcept;
    Q_REQUIRED_RESULT QMap<QString, Optgroup*> optgroupIdMap() const noexcept;

protected:
    Select(SelectPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Select)
    Q_DECLARE_PRIVATE(Select) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_SELECT_H
