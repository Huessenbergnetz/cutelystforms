/*!
 * SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_H
#define C_FORMS_H

#include "cutelyst_plugin_forms_export.h"
#include "form.h"
#include <Cutelyst/plugin.h>

namespace Cutelyst {
class Context;
}

namespace CutelystForms {

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
class CUTELYST_PLUGIN_FORMS_EXPORT Forms : public Cutelyst::Plugin // clazy:exclude=ctor-missing-parent-argument
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Forms) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
    Q_DISABLE_COPY(Forms)
public:
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
    Q_REQUIRED_RESULT QStringList importPaths() const noexcept;

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
    Q_REQUIRED_RESULT QStringList includePaths() const noexcept;

    static Form* getForm(const QString &name, Cutelyst::Context *c);

protected:
    /*!
     * \brief Sets the %Forms plugin up to be used by \a app.
     */
    bool setup(Cutelyst::Application *app) override;

private:
    FormsPrivate *const d_ptr;
};

}

#endif // C_FORMS_H
