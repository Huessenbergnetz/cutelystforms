# SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
# SPDX-License-Identifier: BSD-3-Clause

set(cuteleebootstrap5_SRC
    field.html
    fieldwithlabel.html
    input.html
    inputwithlabel.html
    select.html
    selectwithlabel.html
    textarea.html
    textareawithlabel.html
)

add_custom_target(cuteleebootstrap5
    SOURCES
        ${cuteleebootstrap5_SRC}
)

install(FILES ${cuteleebootstrap5_SRC}
    DESTINATION ${CUTELYSTFORMS_TEMPLATESDIR}/cutelee/bootstrap5/cutelystforms
    COMPONENT templates
)
