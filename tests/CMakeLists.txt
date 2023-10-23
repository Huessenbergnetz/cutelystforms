# SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
# SPDX-License-Identifier: BSD-3-Clause

find_package(QT NAMES Qt6 Qt5 COMPONENTS Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} 5.15.2 COMPONENTS Test REQUIRED)

add_executable(testforms_exec testforms.cpp coverageobject.cpp coverageobject.h)
add_test(NAME testforms COMMAND testforms_exec)
target_link_libraries(testforms_exec Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}::Forms Qt${QT_VERSION_MAJOR}::Test)
target_compile_definitions(testforms_exec
    PRIVATE
        FORMS_IMPORT_DIR="${CMAKE_BINARY_DIR}/Forms/imports"
        TESTFORMS_DIR="${CMAKE_SOURCE_DIR}/tests/data"
)
