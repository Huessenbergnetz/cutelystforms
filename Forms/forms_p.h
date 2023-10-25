/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
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
};

class FormsContextObject : public QObject
{
    Q_OBJECT
public:
    explicit FormsContextObject(const QString &form, Cutelyst::Context *c);

    Q_INVOKABLE QString cTr(const QString &sourceText, const QString &disambiguation = QString(), int n = -1) const;
    Q_INVOKABLE QString cTranslate(const QString &context, const QString &sourceText, const QString &disambiguation = QString(), int n = -1) const;
    Q_INVOKABLE QUrl cUriFor(const QString &path = QString(), const QStringList &args = QStringList(), const QVariantMap &queryValues = QVariantMap()) const;
    Q_INVOKABLE QString cCsrfToken();

private:
    const QString m_form;
    Cutelyst::Context *m_c;
};

}

#endif // C_FORMS_P_H
