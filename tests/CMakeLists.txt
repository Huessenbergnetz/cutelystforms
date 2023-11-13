# SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
# SPDX-License-Identifier: BSD-3-Clause

find_package(Qt${QT_VERSION_MAJOR} ${QT_MINIMUM_VERSION} COMPONENTS Test REQUIRED)

add_executable(testforms_exec testforms.cpp coverageobject.cpp coverageobject.h)
add_test(NAME testforms COMMAND testforms_exec)
target_link_libraries(testforms_exec Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms::Core Qt${QT_VERSION_MAJOR}::Test)
target_compile_definitions(testforms_exec
    PRIVATE
        FORMS_IMPORT_DIR="${CMAKE_BINARY_DIR}/Forms/imports"
        TESTFORMS_L10N_DIR="${CMAKE_CURRENT_BINARY_DIR}/data/l10n"
        TESTFORMS_DIR="${CMAKE_SOURCE_DIR}/tests/data"
)

if (TARGET Cutelyst::CSRFProtection)
    target_compile_definitions(testforms_exec
        PRIVATE PLUGIN_CSRFPROTECTION_ENABLED
    )
    target_link_libraries(testforms_exec Cutelyst::CSRFProtection)
endif (TARGET Cutelyst::CSRFProtection)

set(testforms_TS_FILES
    data/l10n/formtests.de.ts
    data/l10n/formtests.en.ts
)

set_source_files_properties(${testforms_TS_FILES}
    PROPERTIES OUTPUT_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/data/l10n
)

qt_add_lupdate(testforms_exec
    SOURCES data/MyForm.qml
    TS_FILES ${testforms_TS_FILES}
    OPTIONS -no-obsolete -locations none -tr-function-alias qsTr=cTr,qsTranslate=cTranslate
)

qt_add_lrelease(testforms_exec
    TS_FILES ${testforms_TS_FILES}
    QM_FILES_OUTPUT_VARIABLE testforms_QM_FILES
)
