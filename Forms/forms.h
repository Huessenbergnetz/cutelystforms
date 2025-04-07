/*!
 * SPDX-FileCopyrightText: (C) 2023-2025 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_H
#define C_FORMS_H

#include "cutelyst_plugin_forms_export.h"
#include "form.h"

#include <Cutelyst/context.h>
#include <Cutelyst/plugin.h>
#include <coroutine>

#include <QPointer>

namespace CutelystForms {

class AwaitedForm
{
public:
    bool await_ready() const noexcept { return m_hasResult; }

    bool await_suspend(std::coroutine_handle<> handle) noexcept
    {
        m_handle = handle;
        if (m_receiver) {
            m_destroyConn = QObject::connect(m_receiver, &QObject::destroyed, [handle, this] {
                m_hasResult = true;
                handle.resume();
            });
        }

        return !await_ready();
    }

    Form *await_resume() { return m_form; }

    explicit AwaitedForm(Cutelyst::Context *c)
        : m_receiver{c}
    {
        callback = [this](Form *form) {
            m_form      = form;
            m_hasResult = true;

            if (m_handle) {
                m_handle.resume();
            }
        };
    }

protected:
    friend class Forms;
    std::function<void(Form *form)> callback;

private:
    QMetaObject::Connection m_destroyConn;
    QPointer<Cutelyst::Context> m_receiver;
    std::coroutine_handle<> m_handle;
    Form *m_form{nullptr};
    bool m_hasResult{false};
};

class FormsPrivate;

/*!
 * \brief Provides loading and processing HTML form data written in QML.
 *
 * <h3>Logging</h3>
 * Information is logged to the \c cutelyst.forms logging category. Warnings
 * from the internal QQmlEngine will also be redirected to this category.
 *
 * <h3>Building and using</h3>
 * The plugin is linked to %Cutelyst Core API, QtCore and QtQml. If the
 * CSRFProtection plugin is enabled, it will also be linked against that.
 * To use it in your application, link your application to \a Cutelyst::Forms.
 */

/*!
 * \class Forms forms.h <CutelystForms/Forms>
 * \brief The Forms plugin class.
 */
class CUTELYST_PLUGIN_FORMS_EXPORT Forms // clazy:exclude=ctor-missing-parent-argument
    : public Cutelyst::Plugin
{
    Q_OBJECT
public:
    enum Option : int { NoOptions = 0x0, DoNotFillContext = 0x1 };
    Q_DECLARE_FLAGS(Options, Option)
    Q_FLAG(Options)

    /*!
     * \brief Constructs a new %Forms plugin object with the given \a parent.
     */
    explicit Forms(Cutelyst::Application *parent);

    /*!
     * \brief Destroys the %Forms object.
     */
    ~Forms() override;

    /*!
     * \brief Adds an import \a path to the internal QQmlEngine.
     * \sa importPaths(), QQmlEngine::addImportPath()
     */
    void addImportPath(const QString &path);
    /*!
     * \brief Returns the current list of import paths used by the internal QQmlEngine.
     * \sa addImportPath(), QQmlEngine::importPathList()
     */
    [[nodiscard]] QStringList importPaths() const noexcept;

    /*!
     * \brief Sets the list of include \a paths.
     *
     * The include paths are used to load QML files that define a HTML form.
     *
     * Use includePaths() to return a list of currently set paths.
     */
    void setIncludePaths(const QStringList &paths);
    /*!
     * \brief Returns the list of include paths.
     *
     * The include paths are used to load QML files that define a HTML form.
     *
     * Use setIncludePahts() to set the list of paths.
     */
    [[nodiscard]] QStringList includePaths() const noexcept;

    void setTimezoneStashKey(const QString &key);

    static QString timezoneStashKey();

    static Form *getForm(QStringView name, Cutelyst::Context *c, Options options = NoOptions);

    static AwaitedForm
        coGetForm(const QString &name, Cutelyst::Context *c, Options options = NoOptions);

    static QString templatesDirPath();

    static QString templateDirPath(QStringView templ);

protected:
    /*!
     * \brief Sets the %Forms plugin up to be used by \a app.
     */
    bool setup(Cutelyst::Application *app) override;

private:
    friend class FormsLoader;
    FormsPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(Forms) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
    Q_DISABLE_COPY(Forms)
};

} // namespace CutelystForms

Q_DECLARE_OPERATORS_FOR_FLAGS(CutelystForms::Forms::Options)

#endif // C_FORMS_H
