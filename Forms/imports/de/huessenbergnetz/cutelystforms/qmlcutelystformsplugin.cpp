/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <Forms/button.h>
#include <Forms/emailinput.h>
#include <Forms/field.h>
#include <Forms/fieldset.h>
#include <Forms/form.h>
#include <Forms/formhtmlelement.h>
#include <Forms/hiddeninput.h>
#include <Forms/legend.h>
#include <Forms/optgroup.h>
#include <Forms/option.h>
#include <Forms/passwordinput.h>
#include <Forms/searchinput.h>
#include <Forms/select.h>
#include <Forms/selectcontent.h>
#include <Forms/textinput.h>

#include <QtQml>

class QmlCutelystFormsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid FILE "plugin.json")
public:
    QmlCutelystFormsPlugin(QObject *parent = nullptr)
        : QQmlExtensionPlugin(parent)
    {
    }

    void registerTypes(const char *uri) override
    {
        if (Q_LIKELY(QLatin1String(uri) == QLatin1String(FORMS_QML_PLUGIN_URI))) {

            constexpr int major{1};
            constexpr int minor{0};

            // @uri de.huessenbergnetz.cutelystforms
            qmlRegisterAnonymousType<CutelystForms::FormHtmlElement>(uri, major);
            qmlRegisterType<CutelystForms::Form>(uri, major, minor, "Form");
            qmlRegisterType<CutelystForms::Fieldset>(uri, major, minor, "Fieldset");
            qmlRegisterType<CutelystForms::Legend>(uri, major, minor, "Legend");
            qmlRegisterType<CutelystForms::Button>(uri, major, minor, "Button");
            qmlRegisterAnonymousType<CutelystForms::Field>(uri, major);
            qmlRegisterType<CutelystForms::EmailInput>(uri, major, minor, "EmailInput");
            qmlRegisterType<CutelystForms::HiddenInput>(uri, major, minor, "HiddenInput");
            qmlRegisterType<CutelystForms::PasswordInput>(uri, major, minor, "PasswordInput");
            qmlRegisterType<CutelystForms::SearchInput>(uri, major, minor, "SearchInput");
            qmlRegisterType<CutelystForms::TextInput>(uri, major, minor, "TextInput");
            qmlRegisterType<CutelystForms::Select>(uri, major, minor, "Select");
            qmlRegisterAnonymousType<CutelystForms::SelectContent>(uri, major);
            qmlRegisterType<CutelystForms::Option>(uri, major, minor, "Option");
            qmlRegisterType<CutelystForms::Optgroup>(uri, major, minor, "Optgroup");

        } else {
            qCritical() << "Unsupported URI given to load Cutelyst Forms QML plugin:" << uri;
        }
    }
};

#include "qmlcutelystformsplugin.moc"
