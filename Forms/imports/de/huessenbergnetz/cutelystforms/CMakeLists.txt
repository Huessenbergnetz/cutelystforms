# SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
# SPDX-License-Identifier: BSD-3-Clause

find_program(QMAKE_CMD_PATH NAMES qmake-qt${QT_VERSION_MAJOR} qmake${QT_VERSION_MAJOR} qmake)
set(QMAKE_CMD ${QMAKE_CMD_PATH})

# get qmake location and query some Qt installation paths for later use
get_property(QMAKE_EXE_PATH TARGET Qt${QT_VERSION_MAJOR}::qmake PROPERTY LOCATION)

execute_process(COMMAND ${QMAKE_EXE_PATH} -query QT_INSTALL_BINS RESULT_VARIABLE QMAKE_RESULT OUTPUT_VARIABLE QT_INSTALL_BINS OUTPUT_STRIP_TRAILING_WHITESPACE)
if (QMAKE_RESULT)
    message(FATAL_ERROR "Failed to use qmake to query QT_INSTALL_BINS")
endif (QMAKE_RESULT)

execute_process(COMMAND ${QMAKE_EXE_PATH} -query QT_INSTALL_QML RESULT_VARIABLE QMAKE_RESULT OUTPUT_VARIABLE QT_INSTALL_QML OUTPUT_STRIP_TRAILING_WHITESPACE)
if (QMAKE_RESULT)
    message(FATAL_ERROR "Failed to use qmake to query QT_INSTALL_QML")
endif (QMAKE_RESULT)

qt_add_library(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
    qmlcutelystformsplugin.cpp
)

target_link_libraries(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
    PRIVATE Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
)

set(QMLPLUGIN_URI de.huessenbergnetz.cutelystforms)
set(QMLPLUGIN_VERSION 1.0)

target_compile_definitions(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
    PRIVATE
        FORMS_QML_PLUGIN_URI="${QMLPLUGIN_URI}"
)

string(REPLACE "." "/" QMLPLUGIN_INSTALL_URI ${QMLPLUGIN_URI})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir.in ${CMAKE_CURRENT_BINARY_DIR}/qmldir @ONLY)

## Create command to generate plugin.qmltypes after build
add_custom_command(
    TARGET Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
    POST_BUILD
    COMMAND ${QT_INSTALL_BINS}/qmlplugindump -nonrelocatable ${QMLPLUGIN_URI} ${QMLPLUGIN_VERSION} ${CMAKE_BINARY_DIR}/Forms/imports > ${CMAKE_CURRENT_BINARY_DIR}/plugin.qmltypes
    COMMENT "Generating plugin.qmltypes"
)

### Install library
install(TARGETS Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
    DESTINATION ${QT_INSTALL_QML}/${QMLPLUGIN_INSTALL_URI}
)

### Install additional files
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/qmldir
    ${CMAKE_CURRENT_BINARY_DIR}/plugin.qmltypes
    DESTINATION ${QT_INSTALL_QML}/${QMLPLUGIN_INSTALL_URI}
)
