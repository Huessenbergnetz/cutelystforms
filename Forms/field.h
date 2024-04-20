/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_FIELD_H
#define C_FORMS_FIELD_H

#include "cutelyst_plugin_forms_export.h"
#include "formhtmlelement.h"
#include "option.h"
#include "optgroup.h"
#include <QVariant>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

// clazy:excludeall=qproperty-without-notify

namespace CutelystForms {

class FieldPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Field : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(QString accept READ accept WRITE setAccept)
    Q_PROPERTY(QString autocomplete READ autocomplete WRITE setAutocomplete)
    Q_PROPERTY(bool checked READ checked WRITE setChecked)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(bool disabled READ disabled WRITE setDisabled)
    Q_PROPERTY(QString label READ label WRITE setLabel)
    Q_PROPERTY(QString list READ list WRITE setList)
    Q_PROPERTY(QVariant max READ max WRITE setMax)
    Q_PROPERTY(int maxlength READ maxlength WRITE setMaxlength)
    Q_PROPERTY(QVariant min READ min WRITE setMin)
    Q_PROPERTY(int minlength READ minlength WRITE setMinlength)
    Q_PROPERTY(bool multiple READ multiple WRITE setMultiple)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString placeholder READ placeholder WRITE setPlaceholder)
    Q_PROPERTY(QString pattern READ pattern WRITE setPattern)
    Q_PROPERTY(bool readonly READ readonly WRITE setReadonly)
    Q_PROPERTY(bool required READ required WRITE setRequired)
    Q_PROPERTY(QVariant step READ step WRITE setStep)
    Q_PROPERTY(CutelystForms::Field::Type type READ type CONSTANT)
    Q_PROPERTY(QString typeString READ typeString CONSTANT)
    Q_PROPERTY(QVariant value READ value WRITE setValue)

    Q_PROPERTY(QQmlListProperty<CutelystForms::Option> options READ options)
    Q_PROPERTY(QList<CutelystForms::Option*> optionList READ optionList)
    Q_PROPERTY(QMap<QString, CutelystForms::Option*> optionById READ optionIdMap)

    Q_PROPERTY(QQmlListProperty<CutelystForms::Optgroup> optgroups READ optgroups)
    Q_PROPERTY(QList<CutelystForms::Optgroup*> optgroupList READ optgroupList)
    Q_PROPERTY(QMap<QString, CutelystForms::Optgroup*> optgroupById READ optgroupIdMap)

    Q_CLASSINFO("DefaultProperty", "options")
    QML_ANONYMOUS
public:
    explicit Field(QObject *parent = nullptr);
    ~Field() override = default;

    enum Type {
        None            = 0,
        Text,
        Search,
        Password,
        Tel,
        Url,
        Email,
        Number,
        Range,
        Radio,
        Checkbox,
        Hidden,
        File,
        Color,
        Date,
        DatetimeLocal,
        Week,
        Month,
        Time
    };
    Q_ENUM(Type)

    [[nodiscard]] QString accept() const noexcept;
    void setAccept(const QString &accept) noexcept;

    [[nodiscard]] QString autocomplete() const noexcept;
    void setAutocomplete(const QString &autocomplete) noexcept;

    [[nodiscard]] bool checked() const noexcept;
    void setChecked(bool checked) noexcept;

    Q_REQUIRED_RESULT QString description() const noexcept;
    void setDescription(const QString &description) noexcept;

    [[nodiscard]] bool disabled() const noexcept;
    void setDisabled(bool disabled) noexcept;

    Q_REQUIRED_RESULT QString label() const noexcept;
    void setLabel(const QString &label) noexcept;

    [[nodiscard]] QString list() const noexcept;
    void setList(const QString &list) noexcept;

    [[nodiscard]] QVariant max() const noexcept;
    void setMax(const QVariant &max) noexcept;

    [[nodiscard]] int maxlength() const noexcept;
    void setMaxlength(int maxlength) noexcept;

    [[nodiscard]] QVariant min() const noexcept;
    void setMin(const QVariant &min) noexcept;

    [[nodiscard]] int minlength() const noexcept;
    void setMinlength(int minlength) noexcept;

    Q_REQUIRED_RESULT bool multiple() const noexcept;
    void setMultiple(bool multiple) noexcept;

    Q_REQUIRED_RESULT QString name() const noexcept;
    void setName(const QString &name) noexcept;

    [[nodiscard]] QString placeholder() const noexcept;
    void setPlaceholder(const QString &placeholder) noexcept;

    [[nodiscard]] QString pattern() const noexcept;
    void setPattern(const QString &pattern) noexcept;

    [[nodiscard]] bool readonly() const noexcept;
    void setReadonly(bool readonly) noexcept;

    [[nodiscard]] bool required() const noexcept;
    void setRequired(bool required) noexcept;

    [[nodiscard]] QVariant step() const noexcept;
    void setStep(const QVariant &step) noexcept;

    Q_REQUIRED_RESULT virtual Field::Type type() const noexcept;

    Q_REQUIRED_RESULT virtual QString typeString() const noexcept;

    [[nodiscard]] QVariant value() const noexcept;
    void setValue(const QVariant &value) noexcept;

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
    Field(FieldPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Field)
    Q_DECLARE_PRIVATE(Field) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_FIELD_H
