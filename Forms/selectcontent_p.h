/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_SELECTCONTENT_P_H
#define C_FORMS_SELECTCONTENT_P_H

#include "formhtmlelement_p.h"
#include "selectcontent.h"

namespace CutelystForms {

class SelectContentPrivate : public FormHtmlElementPrivate
{
public:
    SelectContentPrivate(SelectContent *q);
    SelectContentPrivate(const QString &_label, SelectContent *q);
    ~SelectContentPrivate() override = default;

    QStringList attrList() const override;

    QString label;
    bool disabled{false};

private:
    Q_DECLARE_PUBLIC(SelectContent) // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    Q_DISABLE_COPY(SelectContentPrivate)
};

} // namespace CutelystForms

#endif // C_FORMS_SELECTCONTENT_P_H
