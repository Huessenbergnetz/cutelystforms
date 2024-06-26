/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_P_H
#define C_FORMS_P_H

#include "forms.h"

#include <QQmlEngine>

namespace CutelystForms {

class FormsPrivate
{
public:
    QQmlEngine engine;
    QStringList includePaths;
    QString timezoneStashKey;
};

class FormsContextObject final : public QObject // clazy:exclude=ctor-missing-parent-argument
{
    Q_OBJECT
public:
    explicit FormsContextObject(const QString &form, Cutelyst::Context *c);
    ~FormsContextObject() override = default;

    [[nodiscard]] Q_INVOKABLE QString cTr(const QString &sourceText,
                                          const QString &disambiguation = QString(),
                                          int n                         = -1) const;
    [[nodiscard]] Q_INVOKABLE QString cTrId(const QString &id, int n = -1) const;
    [[nodiscard]] Q_INVOKABLE QString cTranslate(const QString &context,
                                                 const QString &sourceText,
                                                 const QString &disambiguation = QString(),
                                                 int n                         = -1) const;
    [[nodiscard]] Q_INVOKABLE QUrl cUriFor(const QString &path            = QString(),
                                           const QStringList &args        = QStringList(),
                                           const QVariantMap &queryValues = QVariantMap()) const;
    [[nodiscard]] Q_INVOKABLE QString cCsrfToken() const;
    [[nodiscard]] Q_INVOKABLE QString cCsrfTokenFieldName() const;
    [[nodiscard]] Q_INVOKABLE QVariant cStashValue(const QString &key,
                                                   const QVariant &defVal = QVariant());

private:
    const QString m_form;
    Cutelyst::Context *m_c;

    Q_DISABLE_COPY(FormsContextObject)
};

} // namespace CutelystForms

#endif // C_FORMS_P_H
