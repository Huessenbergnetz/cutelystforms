/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <Forms/formhtmlelement.h>
#include <Forms/form.h>
#include <Forms/fieldset.h>
#include <Forms/legend.h>
#include <Forms/button.h>
#include <Forms/field.h>
#include <Forms/input.h>
#include <Forms/hiddeninput.h>
#include <Forms/select.h>
#include <Forms/selectcontent.h>
#include <Forms/option.h>
#include <Forms/optgroup.h>
#include <Forms/emailinput.h>
#include <Forms/textinput.h>

#include <QtQml>

class QmlCutelystFormsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid FILE "plugin.json")
public:
    QmlCutelystFormsPlugin(QObject *parent = nullptr) : QQmlExtensionPlugin(parent) {}

    void registerTypes(const char *uri) override
    {
        if (Q_LIKELY(QLatin1String(uri) == QLatin1String(FORMS_QML_PLUGIN_URI))) {

            const int major = 1;
            const int minor = 0;

            // @uri org.cutelyst.forms
            qmlRegisterAnonymousType<CutelystForms::FormHtmlElement>(uri, major);
            qmlRegisterType<CutelystForms::Form>(uri, major, minor, "Form");
            qmlRegisterType<CutelystForms::Fieldset>(uri, major, minor, "Fieldset");
            qmlRegisterType<CutelystForms::Legend>(uri, major, minor, "Legend");
            qmlRegisterType<CutelystForms::Button>(uri, major, minor, "Button");
            qmlRegisterAnonymousType<CutelystForms::Field>(uri, major);
            qmlRegisterAnonymousType<CutelystForms::Input>(uri, major);
            qmlRegisterType<CutelystForms::HiddenInput>(uri, major, minor, "HiddenInput");
            qmlRegisterType<CutelystForms::EmailInput>(uri, major, minor, "EmailInput");
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
