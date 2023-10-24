# SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
# SPDX-License-Identifier: BSD-3-Clause

find_program(QMAKE_CMD_PATH NAMES qmake-qt${QT_VERSION_MAJOR} qmake${QT_VERSION_MAJOR} qmake)
set(QMAKE_CMD ${QMAKE_CMD_PATH})

### Finds where to qmlplugindump binary is installed
### Requires that 'qmake' directory is in PATH
function(FindQmlPluginDump)
    execute_process(
        COMMAND ${QMAKE_CMD} -query QT_INSTALL_BINS
        OUTPUT_VARIABLE QT_BIN_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    set(QMLPLUGINDUMP_BIN ${QT_BIN_DIR}/qmlplugindump PARENT_SCOPE)
endfunction()

### Sets QT_INSTALL_QML to the directory where QML Plugins should be installed
function(FindQtInstallQml)
    execute_process(
        COMMAND ${QMAKE_CMD} -query QT_INSTALL_QML
        OUTPUT_VARIABLE PROC_RESULT
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    set(QT_INSTALL_QML ${PROC_RESULT} PARENT_SCOPE)
endfunction()

set(qml_plugin_forms_SRC
    qmlcutelystformsplugin.cpp
)

add_library(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
    ${qml_plugin_forms_SRC}
)

add_library(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms::Qml ALIAS Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml)

target_compile_definitions(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
    PRIVATE
        QT_NO_KEYWORDS
        QT_NO_CAST_TO_ASCII
        QT_NO_CAST_FROM_ASCII
        QT_STRICT_ITERATORS
        QT_NO_URL_CAST_FROM_STRING
        QT_NO_CAST_FROM_BYTEARRAY
        QT_USE_QSTRINGBUILDER
        QT_NO_SIGNALS_SLOTS_KEYWORDS
        QT_USE_FAST_OPERATOR_PLUS
        QT_DISABLE_DEPRECATED_BEFORE=0x050E00
)

set_target_properties(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml PROPERTIES
    AUTOMOC ON
    AUTORCC ON
)

target_link_libraries(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
    PRIVATE Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}::Forms
    PRIVATE Qt${QT_VERSION_MAJOR}::Core
    PRIVATE Qt${QT_VERSION_MAJOR}::Qml
)

### Find location of qmlplugindump (stored in QMLPLUGINDUMP_BIN)
FindQmlPluginDump()
### Find where to install QML Plugins (stored in QT_INSTALL_QML)
FindQtInstallQml()

set(QMLPLUGIN_URI de.huessenbergnetz.cutelystforms)
set(QMLPLUGIN_VERSION 1.0)

target_compile_definitions(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
    PRIVATE
        FORMS_QML_PLUGIN_URI="${QMLPLUGIN_URI}"
)

string(REPLACE "." "/" QMLPLUGIN_INSTALL_URI ${QMLPLUGIN_URI})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir.in ${CMAKE_CURRENT_BINARY_DIR}/qmldir @ONLY)

#set(GENERATE_QMLTYPES_COMMAND ${QMLPLUGINDUMP_BIN} -nonrelocatable ${QMLPLUGIN_URI} ${QMLPLUGIN_VERSION} ${CMAKE_BINARY_DIR}/Cutelyst/Plugins/Forms/imports > ${CMAKE_CURRENT_BINARY_DIR}/plugin.qmltypes)
set(GENERATE_QMLTYPES_COMMAND ${QMLPLUGINDUMP_BIN} -nonrelocatable ${QMLPLUGIN_URI} ${QMLPLUGIN_VERSION} ${CMAKE_BINARY_DIR}/Forms/imports > ${CMAKE_CURRENT_BINARY_DIR}/plugin.qmltypes)

## Create command to generate plugin.qmltypes after build
add_custom_command(
    TARGET Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
    POST_BUILD
    COMMAND ${GENERATE_QMLTYPES_COMMAND}
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
