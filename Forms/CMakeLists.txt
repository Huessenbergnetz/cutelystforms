# SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
# SPDX-License-Identifier: BSD-3-Clause

set(cutelystforms_SRC
    logging_p.h
    forms.cpp
    forms_p.h
    formhtmlelement.cpp
    formhtmlelement_p.h
    form.cpp
    form_p.h
    fieldset.cpp
    fieldset_p.h
    legend.cpp
    legend_p.h
    button.cpp
    button_p.h
    field.cpp
    field_p.h
    select.cpp
    select_p.h
    selectcontent.cpp
    selectcontent_p.h
    option.cpp
    option_p.h
    optgroup.cpp
    optgroup_p.h
    hiddeninput.cpp
    hiddeninput_p.h
    namedlistproperty_p.h
    emailinput.cpp
    emailinput_p.h
    textinput.cpp
    textinput_p.h
    searchinput.cpp
    searchinput_p.h
    passwordinput.cpp
    passwordinput_p.h
    telinput.cpp
    telinput_p.h
    urlinput.cpp
    urlinput_p.h
    dateinput.cpp
    dateinput_p.h
    datetimelocalinput.cpp
    datetimelocalinput_p.h
    weekinput.cpp
    weekinput_p.h
    timeinput.cpp
    timeinput_p.h
    monthinput.cpp
    monthinput_p.h
    numberinput.cpp
    numberinput_p.h
    rangeinput.cpp
    rangeinput_p.h
    colorinput.cpp
    colorinput_p.h
    checkboxinput.cpp
    checkboxinput_p.h
    radioinput.cpp
    radioinput_p.h
    fileinput.cpp
    fileinput_p.h
)

set(cutelystforms_HEADERS
    ${CMAKE_CURRENT_BINARY_DIR}/cutelyst_plugin_forms_export.h
    forms.h
    formhtmlelement.h
    form.h
    fieldset.h
    legend.h
    button.h
    field.h
    select.h
    selectcontent.h
    option.h
    optgroup.h
    hiddeninput.h
    emailinput.h
    textinput.h
    searchinput.h
    passwordinput.h
    telinput.h
    urlinput.h
    dateinput.h
    datetimelocalinput.h
    weekinput.h
    timeinput.h
    monthinput.h
    numberinput.h
    rangeinput.h
    colorinput.h
    checkboxinput.h
    radioinput.h
    fileinput.h
)

add_library(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
    ${cutelystforms_SRC}
    ${cutelystforms_HEADERS}
)

add_library(CutelystForms::Core ALIAS Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms)

generate_export_header(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms BASE_NAME cutelyst_plugin_forms)

target_include_directories(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/cutelyst${CUTELYST_VERSION_MAJOR}forms-qt${QT_VERSION_MAJOR}>
)

GNUInstallDirs_get_absolute_install_dir(CUTELYSTFORMS_FULL_TEMPLATESDIR CUTELYSTFORMS_TEMPLATESDIR DATADIR)

target_compile_definitions(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
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
        CUTELYSTFORMS_TEMPLATESDIR="${CUTELYSTFORMS_FULL_TEMPLATESDIR}"
)

set_target_properties(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms PROPERTIES
    EXPORT_NAME Core
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER "${cutelystforms_HEADERS}"
)

target_link_libraries(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
    PUBLIC
        Cutelyst::Core
        Qt::Core
        Qt::Qml
)

set(PLUGIN_FORMS_PKGCONFIG_REQUIRES "Qt${QT_VERSION_MAJOR}Core Qt${QT_VERSION_MAJOR}Qml Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Core")
set(PLUGIN_FORMS_PKGCONFIG_LIBS "-lQt${QT_VERSION_MAJOR}Core -lQt${QT_VERSION_MAJOR}Qml -lCutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Core")

if (TARGET Cutelyst::CSRFProtection)
    message(STATUS "Cutelyst::CSRFProtection available")
    target_link_libraries(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
        PRIVATE Cutelyst::CSRFProtection
    )
    target_compile_definitions(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
        PRIVATE PLUGIN_CSRFPROTECTION_ENABLED
    )
    set(PLUGIN_FORMS_PKGCONFIG_REQUIRES "${PLUGIN_FORMS_PKGCONFIG_REQUIRES} Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}CSRFProtection")
    set(PLUGIN_FORMS_PKGCONFIG_LIBS "${PLUGIN_FORMS_PKGCONFIG_LIBS} -lCutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}CSRFProtection")
endif (TARGET Cutelyst::CSRFProtection)

install(TARGETS Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
    EXPORT CutelystFormsTargets DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT runtime
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT devel
    PUBLIC_HEADER DESTINATION include/cutelyst${CUTELYST_VERSION_MAJOR}forms-qt${QT_VERSION_MAJOR}/CutelystForms COMPONENT devel
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CutelystQtForms.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms.pc
    @ONLY
)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms.pc
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

add_subdirectory("imports/de/huessenbergnetz/cutelystforms")
