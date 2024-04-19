# SPDX-FileCopyrightText: (C) 2024 Matthias Fehring <https://www.huessenbergnetz.de>
# SPDX-License-Identifier: BSD-3-Clause

set(cuteleebootstrap5_SRC
    input.html
    inputwithlabel.html
)

add_custom_target(cuteleebootstrap5
    SOURCES
        ${cuteleebootstrap5_SRC}
)

install(FILES ${cuteleebootstrap5_SRC}
    DESTINATION ${CUTELYSTFORMS_TEMPLATESDIR}/cutelee/bootstrap5/cutelystforms
    COMPONENT templates
)
