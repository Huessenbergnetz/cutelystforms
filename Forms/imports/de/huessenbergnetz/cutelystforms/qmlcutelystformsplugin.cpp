/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <Forms/button.h>
#include <Forms/checkboxinput.h>
#include <Forms/colorinput.h>
#include <Forms/dateinput.h>
#include <Forms/datetimelocalinput.h>
#include <Forms/emailinput.h>
#include <Forms/field.h>
#include <Forms/fieldset.h>
#include <Forms/fileinput.h>
#include <Forms/form.h>
#include <Forms/formhtmlelement.h>
#include <Forms/hiddeninput.h>
#include <Forms/monthinput.h>
#include <Forms/numberinput.h>
#include <Forms/optgroup.h>
#include <Forms/option.h>
#include <Forms/passwordinput.h>
#include <Forms/radioinput.h>
#include <Forms/rangeinput.h>
#include <Forms/searchinput.h>
#include <Forms/select.h>
#include <Forms/selectcontent.h>
#include <Forms/telinput.h>
#include <Forms/textarea.h>
#include <Forms/textinput.h>
#include <Forms/timeinput.h>
#include <Forms/urlinput.h>
#include <Forms/weekinput.h>

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
            qmlRegisterType<CutelystForms::Button>(uri, major, minor, "FormButton");
            qmlRegisterAnonymousType<CutelystForms::Field>(uri, major);
            qmlRegisterType<CutelystForms::CheckboxInput>(uri, major, minor, "CheckBoxForm");
            qmlRegisterType<CutelystForms::ColorInput>(uri, major, minor, "ColorForm");
            qmlRegisterType<CutelystForms::DateInput>(uri, major, minor, "DateForm");
            qmlRegisterType<CutelystForms::DateTimeLocalInput>(
                uri, major, minor, "DateTimeLocalForm");
            qmlRegisterType<CutelystForms::EmailInput>(uri, major, minor, "EmailForm");
            qmlRegisterType<CutelystForms::FileInput>(uri, major, minor, "FileForm");
            qmlRegisterType<CutelystForms::HiddenInput>(uri, major, minor, "HiddenForm");
            qmlRegisterType<CutelystForms::MonthInput>(uri, major, minor, "MonthForm");
            qmlRegisterType<CutelystForms::NumberInput>(uri, major, minor, "NumberForm");
            qmlRegisterType<CutelystForms::PasswordInput>(uri, major, minor, "PasswordForm");
            qmlRegisterType<CutelystForms::RadioInput>(uri, major, minor, "RadioForm");
            qmlRegisterType<CutelystForms::RangeInput>(uri, major, minor, "RangeForm");
            qmlRegisterType<CutelystForms::SearchInput>(uri, major, minor, "SearchForm");
            qmlRegisterType<CutelystForms::TelInput>(uri, major, minor, "TelForm");
            qmlRegisterType<CutelystForms::Textarea>(uri, major, minor, "TextAreaForm");
            qmlRegisterType<CutelystForms::TextInput>(uri, major, minor, "TextForm");
            qmlRegisterType<CutelystForms::TimeInput>(uri, major, minor, "TimeForm");
            qmlRegisterType<CutelystForms::UrlInput>(uri, major, minor, "UrlForm");
            qmlRegisterType<CutelystForms::WeekInput>(uri, major, minor, "WeekForm");
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
