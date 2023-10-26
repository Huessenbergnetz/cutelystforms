/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_SELECT_H
#define C_FORMS_SELECT_H

#include "cutelyst_plugin_forms_export.h"
#include "field.h"
#include "selectcontent.h"
#include <QObject>
#include <QQmlListProperty>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtQml/qqmlregistration.h>
#else
#include <QtQml/qqml.h>
#endif

namespace CutelystForms {

class SelectPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Select : public Field
{
    Q_OBJECT
    Q_PROPERTY(bool multiple READ multiple WRITE setMultiple)
    Q_PROPERTY(int size READ size WRITE setSize)
    Q_PROPERTY(QQmlListProperty<CutelystForms::SelectContent> options READ options)
    Q_CLASSINFO("DefaultProperty", "options")
    QML_ELEMENT
public:
    explicit Select(QObject *parent = nullptr);
    ~Select() override = default;

    Q_REQUIRED_RESULT bool multiple() const noexcept;
    void setMultiple(bool multiple) noexcept;

    Q_REQUIRED_RESULT int size() const noexcept;
    void setSize(int size) noexcept;

    QQmlListProperty<CutelystForms::SelectContent> options();
    void appendContent(SelectContent *content);
    Q_REQUIRED_RESULT QList<SelectContent*>::size_type contentCount() const;
    Q_REQUIRED_RESULT SelectContent *content(QList<SelectContent*>::size_type idx) const;
    void clearContent();
    Q_REQUIRED_RESULT QList<SelectContent *> contentList() const noexcept;

protected:
    Select(SelectPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Select)
    Q_DECLARE_PRIVATE(Select) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
};

}

#endif // C_FORMS_SELECT_H
