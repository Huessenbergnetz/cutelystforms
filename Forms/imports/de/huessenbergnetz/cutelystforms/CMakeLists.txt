# SPDX-FileCopyrightText: (C) 2023-2025 Matthias Fehring <https://www.huessenbergnetz.de>
# SPDX-License-Identifier: BSD-3-Clause

# get qmake location and query some Qt installation paths for later use
get_property(QMAKE_EXE_PATH TARGET Qt${QT_VERSION_MAJOR}::qmake PROPERTY LOCATION)

execute_process(COMMAND ${QMAKE_EXE_PATH} -query QT_INSTALL_QML RESULT_VARIABLE QMAKE_RESULT OUTPUT_VARIABLE QT_INSTALL_QML OUTPUT_STRIP_TRAILING_WHITESPACE)
if (QMAKE_RESULT)
    message(FATAL_ERROR "Failed to use qmake to query QT_INSTALL_QML")
endif (QMAKE_RESULT)

set(QMLPLUGIN_URI de.huessenbergnetz.cutelyst${CUTELYST_VERSION_MAJOR}forms)
set(QMLPLUGIN_VERSION 1.0)

string(REPLACE "." "/" QMLPLUGIN_INSTALL_URI ${QMLPLUGIN_URI})

set(QMLPLUGIN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/Forms/imports/${QMLPLUGIN_INSTALL_URI})

# qt_add_qml_module has some issues when used on Qt below 6.8 I can not figure out
# so I used the deprecated approach for Qt below 6.8
if(${Qt${QT_VERSION_MAJOR}_VERSION} VERSION_GREATER_EQUAL "6.8.0")

    qt_add_qml_module(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
        URI ${QMLPLUGIN_URI}
        VERSION ${QMLPLUGIN_VERSION}
        CLASS_NAME QmlCutelystFormsPlugin
        PLUGIN_TARGET Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
        TYPEINFO Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml.qmltypes
        OUTPUT_DIRECTORY ${QMLPLUGIN_OUTPUT_DIR}
    )

else(${Qt${QT_VERSION_MAJOR}_VERSION} VERSION_GREATER_EQUAL "6.8.0")

    execute_process(COMMAND ${QMAKE_EXE_PATH} -query QT_INSTALL_BINS RESULT_VARIABLE QMAKE_RESULT OUTPUT_VARIABLE QT_INSTALL_BINS OUTPUT_STRIP_TRAILING_WHITESPACE)
    if (QMAKE_RESULT)
        message(FATAL_ERROR "Failed to use qmake to query QT_INSTALL_BINS")
    endif (QMAKE_RESULT)

    qt_add_library(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
        qmlcutelystformsplugin.cpp
    )

    set_target_properties(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
        PROPERTIES
            LIBRARY_OUTPUT_DIRECTORY ${QMLPLUGIN_OUTPUT_DIR}
    )

    target_link_libraries(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
        PRIVATE Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
    )

    target_compile_definitions(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
        PRIVATE
            FORMS_QML_PLUGIN_URI="${QMLPLUGIN_URI}"
    )

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir.in ${QMLPLUGIN_OUTPUT_DIR}/qmldir @ONLY)

    ## Create command to generate plugin.qmltypes after build
    add_custom_command(
        TARGET Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
        POST_BUILD
        COMMAND ${QT_INSTALL_BINS}/qmlplugindump -nonrelocatable ${QMLPLUGIN_URI} ${QMLPLUGIN_VERSION} ${CMAKE_BINARY_DIR}/Forms/imports > ${QMLPLUGIN_OUTPUT_DIR}/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml.qmltypes
        COMMENT "Generating ${QMLPLUGIN_OUTPUT_DIR}/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml.qmltypes"
    )

endif(${Qt${QT_VERSION_MAJOR}_VERSION} VERSION_GREATER_EQUAL "6.8.0")

### Install library
install(TARGETS Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml
    DESTINATION ${QT_INSTALL_QML}/${QMLPLUGIN_INSTALL_URI}
)

### Install additional files
install(FILES
    ${QMLPLUGIN_OUTPUT_DIR}/qmldir
    ${QMLPLUGIN_OUTPUT_DIR}/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsQml.qmltypes
    DESTINATION ${QT_INSTALL_QML}/${QMLPLUGIN_INSTALL_URI}
)
