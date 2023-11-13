# SPDX-FileCopyrightText: (C) 2023 Matthias Fehring <https://www.huessenbergnetz.de>
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)

# cmake_policy(SET CMP0048 NEW)
# cmake_policy(SET CMP0043 NEW)
# cmake_policy(SET CMP0063 NEW)

project(cutelystforms
    VERSION 0.0.1
    DESCRIPTION "A Cutelyst plugin to load forms data from QML files."
    HOMEPAGE_URL "https://github.com/Huessenbergnetz/cutelystforms"
    LANGUAGES CXX
)

include(GNUInstallDirs)
include(GenerateExportHeader)
include(CMakePackageConfigHelpers)

set(CUTELYST_VERSION_MAJOR 4)
set(QT_VERSION_MAJOR 6)
set(QT_MINIMUM_VERSION 6.2)

find_package(Qt${QT_VERSION_MAJOR} ${QT_MINIMUM_VERSION} COMPONENTS Core Qml LinguistTools REQUIRED)
find_package(Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR} 3.8.0 REQUIRED)

set(CUTELYSTFORMS_API_LEVEL "0")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

# Auto generate moc files
set(CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

# Forbid in-tree building
if(${CMAKE_SOURCE_DIR} MATCHES ${CMAKE_BINARY_DIR})
      message(STATUS "Please do an out-of-tree build:")
      message(STATUS "rm -f CMakeCache.txt && mkdir build && cd build; cmake .. && make")
      message(FATAL_ERROR "In-tree-build detected!")
endif(${CMAKE_SOURCE_DIR} MATCHES ${CMAKE_BINARY_DIR})

option(BUILD_SHARED_LIBS "Build in shared lib mode" ON)
option(ENABLE_TESTS "Build the unit tests" OFF)
option(BUILD_DOCS "Enable the build of doxygen docs" OFF)
option(BUILD_DOCS_QUIET "Tell doxygen to be quiet while building the documentation." OFF)

if (ENABLE_TESTS)
    enable_testing()
endif (ENABLE_TESTS)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "libfirfuorida default install prefix" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsConfigVersion.cmake
    VERSION ${cutelystforms_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/CutelystForms-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
    COMPONENT development
)

install(EXPORT CutelystFormsTargets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
    FILE Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsTargets.cmake
    NAMESPACE CutelystForms::
    COMPONENT development
)

add_subdirectory(Forms)
if (ENABLE_TESTS)
    add_subdirectory(tests)
endif (ENABLE_TESTS)

if (BUILD_DOCS)
    find_package(Doxygen REQUIRED dot)

    # Umbreall target to build local docs in HTML and QCH format
    add_custom_target(docs)

    if (BUILD_DOCS_QUIET)
        set(DOXYGEN_QUIET "YES")
        set(DOXYGEN_WARNINGS "NO")
        set(DOXYGEN_WARN_IF_UNDOCUMENTED "NO")
        set(DOXYGEN_WARN_IF_DOC_ERROR "NO")
    else(BUILD_DOCS_QUIET)
        set(DOXYGEN_QUIET "NO")
        set(DOXYGEN_WARNINGS "YES")
        set(DOXYGEN_WARN_IF_UNDOCUMENTED "YES")
        set(DOXYGEN_WARN_IF_DOC_ERROR "YES")
    endif(BUILD_DOCS_QUIET)

    ## Project related configuration options
    set(DOXYGEN_ALWAYS_DETAILED_SEC "YES")
    set(DOXYGEN_STRIP_FROM_PATH ${CMAKE_SOURCE_DIR})
    set(DOXYGEN_BUILTIN_STL_SUPPORT "YES")
    ## Build related configuration options
    set(DOXYGEN_HIDE_UNDOC_MEMBERS "YES")
    set(DOXYGEN_HIDE_UNDOC_CLASSES "YES")
    set(DOXYGEN_SORT_BRIEF_DOCS "YES")
    set(DOXYGEN_SORT_MEMBERS_CTORS_1ST "YES")
    set(DOXYGEN_SHOW_USED_FILES "NO")
    set(DOXYGEN_LAYOUT_FILE ${CMAKE_SOURCE_DIR}/dox/DoxygenLayout.xml)
    ## Configuration options related to the input files
    set(DOXYGEN_FILE_PATTERNS *.cpp *.h *.dox *.md)
#    set(DOXYGEN_EXAMPLE_PATH ${CMAKE_SOURCE_DIR}/dox/examples)
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE ${CMAKE_SOURCE_DIR}/README.md)
    ##  Configuration options related to source browsing
    set(DOXYGEN_VERBATIM_HEADERS "NO")
    ## Configuration options related to external references
    set(DOXYGEN_EXTERNAL_GROUPS "NO")
    set(DOXYGEN_EXTERNAL_PAGES "NO")
    set(DOXYGEN_GENERATE_TAGFILE ${CMAKE_CURRENT_BINARY_DIR}/cutelystforms.tags)
    ## Configuration options related to diagram generator tools
    set(DOXYGEN_COLLABORATION_GRAPH "NO")
    if (DOXYGEN_VERSION VERSION_GREATER_EQUAL 1.9.5)
        set(DOXYGEN_DOT_COMMON_ATTR "fontname=FreeSans,fontsize=10")
        set(DOXYGEN_DOT_EDGE_ATTR "labelfontname=FreeSans,labelfontsize=10")
    else (DOXYGEN_VERSION VERSION_GREATER_EQUAL 1.9.5)
        set(DOXYGEN_DOT_FONTNAME "FreeSans")
        set(DOXYGEN_DOT_FONTSIZE 10)
    endif (DOXYGEN_VERSION VERSION_GREATER_EQUAL 1.9.5)

    find_program(QMAKE_EXE_PATH NAMES qmake-qt${QT_VERSION_MAJOR} qmake${QT_VERSION_MAJOR} qmake)
    if (QMAKE_EXE_PATH)
        execute_process(COMMAND ${QMAKE_EXE_PATH} -query QT_INSTALL_DOCS OUTPUT_VARIABLE QT_INSTALL_DOCS OUTPUT_STRIP_TRAILING_WHITESPACE)
        if (NOT IS_DIRECTORY "${QT_INSTALL_DOCS}")
            set(QT_INSTALL_DOCS "/usr/share/qt${QT_VERSION_MAJOR}/doc")
        endif (NOT IS_DIRECTORY "${QT_INSTALL_DOCS}")
    else (QMAKE_EXE_PATH)
        set(QT_INSTALL_DOCS "/usr/share/qt${QT_VERSION_MAJOR}/doc")
    endif (QMAKE_EXE_PATH)

    set(QT_ONLINE_DOCS_URL "https://doc.qt.io/qt-${QT_VERSION_MAJOR}/")
    set(QT_DOCS_COMPONENTS "qtcore" "qtqml")

    set(DOCS_QTDOCSDIR ${QT_INSTALL_DOCS} CACHE PATH "Path to a directory containing the Qt Documentation")

    message(STATUS "Searching for Qt documentation at ${DOCS_QTDOCSDIR}")

    foreach(_QTDOCCOMP ${QT_DOCS_COMPONENTS})
        find_file(_QTDOCCOMPTAGS "${_QTDOCCOMP}.tags" PATHS "${DOCS_QTDOCSDIR}" PATH_SUFFIXES "${_QTDOCCOMP}" NO_DEFAULT_PATH)
        if (_QTDOCCOMPTAGS)
            message(STATUS "Found ${_QTDOCCOMP}.tags")
            list(APPEND ONLINETAGS "${_QTDOCCOMPTAGS}=${QT_ONLINE_DOCS_URL}")
            if (EXISTS "${DOCS_QTDOCSDIR}/${_QTDOCCOMP}.qch")
                message(STATUS "Found local qch docs for ${_QTDOCCOMP}")
                list(APPEND QCHTAGS "${_QTDOCCOMPTAGS}=qthelp://org.qt-project.${_QTDOCCOMP}.${QT_VERSION_MAJOR}${QT_VERSION_MINOR}${QT_VERSION_PATCH}/${_QTDOCCOMP}/")
            endif (EXISTS "${DOCS_QTDOCSDIR}/${_QTDOCCOMP}.qch")
            if (IS_DIRECTORY "${DOCS_QTDOCSDIR}/${_QTDOCCOMP}")
                message(STATUS "Found local html docs for ${_QTDOCCOMP}")
                list(APPEND LOCALHTMLTAGS "${_QTDOCCOMPTAGS}=${DOCS_QTDOCSDIR}/${_QTDOCCOMP}/")
            endif (IS_DIRECTORY "${DOCS_QTDOCSDIR}/${_QTDOCCOMP}")
        endif (_QTDOCCOMPTAGS)
        unset(_QTDOCCOMPTAGS CACHE)
    endforeach(_QTDOCCOMP ${QT_DOCS_COMPONENTS})

    set(CUTELYST_ONLINE_DOCS_URL "https://api.cutelyst.org/")
    set(CUTELYST_DOCS_COMP "cutelyst3")

    find_file(_CUTELYSTTAGS "${CUTELYST_DOCS_COMP}.tags" PATHS "${DOCS_QTDOCSDIR}" PATH_SUFFIXES "${CUTELYST_DOCS_COMP}" NO_DEFAULT_PATH)
    if (_CUTELYSTTAGS)
        message(STATUS "Found ${CUTELYST_DOCS_COMP}.tags")
        list(APPEND ONLINETAGS "${_CUTELYSTTAGS}=${CUTELYST_ONLINE_DOCS_URL}")
        if (EXISTS "${DOCS_QTDOCSDIR}/${CUTELYST_DOCS_COMP}.qch")
            list(APPEND QCHTAGS "${_CUTELYSTTAGS}=qthelp://org.cutelyst.${Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}_VERSION_MAJOR}${Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}_VERSION_MINOR}${Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}_VERSION_PATCH}/cutelyst${Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}_VERSION_MAJOR}/")
            message(STATUS "Found local qch docs for ${CUTELYST_DOCS_COMP}")
        endif (EXISTS "${DOCS_QTDOCSDIR}/${CUTELYST_DOCS_COMP}.qch")
        if (IS_DIRECTORY "${DOCS_QTDOCSDIR}/${CUTELYST_DOCS_COMP}")
            message(STATUS "Found local html docs for ${CUTELYST_DOCS_COMP}")
            list(APPEND LOCALHTMLTAGS "${_CUTELYSTTAGS}=${DOCS_QTDOCSDIR}/${CUTELYST_DOCS_COMP}/")
        endif (IS_DIRECTORY "${DOCS_QTDOCSDIR}/${CUTELYST_DOCS_COMP}")
    endif (_CUTELYSTTAGS)

    set(DOXYGEN_HTML_TIMESTAMP "YES")
    set(DOXYGEN_TAGFILES ${ONLINETAGS})
    set(DOXYGEN_HTML_OUTPUT "webdocs")
    doxygen_add_docs(webdocs
        ${CMAKE_CURRENT_SOURCE_DIR}/Forms
        COMMENT "Generate HTML documentation for online usage"
    )
    message(STATUS "Adding build target webdocs")

    set(DOXYGEN_HTML_TIMESTAMP "NO")
    set(DOXYGEN_TAGFILES ${LOCALHTMLTAGS})
    set(DOXYGEN_HTML_OUTPUT "htmldocs")
    doxygen_add_docs(htmldocs
        ${CMAKE_CURRENT_SOURCE_DIR}/Forms
        COMMENT "Generate HTML documentation for local usage"
    )
    add_dependencies(docs htmldocs)
    message(STATUS "Adding build target htmldocs")

    execute_process(COMMAND ${QMAKE_EXE_PATH} -query QT_INSTALL_LIBEXECS OUTPUT_VARIABLE QT_INSTALL_LIBEXECS OUTPUT_STRIP_TRAILING_WHITESPACE)
    execute_process(COMMAND ${QMAKE_EXE_PATH} -query QT_INSTALL_BINS OUTPUT_VARIABLE QT_INSTALL_BINS OUTPUT_STRIP_TRAILING_WHITESPACE)
    find_program(DOXYGEN_QHG_LOCATION NAMES qhelpgenerator-qt${QT_VERSION_MAJOR} qhelpgenerator${QT_VERSION_MAJOR} qhelpgenerator HINTS ${QT_INSTALL_LIBEXECS} ${QT_INSTALL_BINS})
    if(DOXYGEN_QHG_LOCATION)
        set(DOXYGEN_TAGFILES ${QCHTAGS})
        set(DOXYGEN_HTML_OUTPUT "qtdocs")
        set(DOXYGEN_GENERATE_QHP "YES")
        set(DOXYGEN_QHP_NAMESPACE "de.huessenbergnetz.cutelystforms.${PROJECT_VERSION_MAJOR}${PROJECT_VERSION_MINOR}${PROJECT_VERSION_PATCH}")
        set(DOXYGEN_QHP_VIRTUAL_FOLDER "cutelystforms")
        set(DOXYGEN_QCH_FILE "${CMAKE_CURRENT_BINARY_DIR}/cutelyst${CUTELYST_VERSION_MAJOR}forms.qch")
        set(DOXYGEN_SEARCHENGINE "NO")
        doxygen_add_docs(qtdocs
            ${CMAKE_CURRENT_SOURCE_DIR}/Forms
            COMMENT "Generate Qt QCH documentation for local usage"
        )
        add_dependencies(docs qtdocs)
        message(STATUS "Adding build target qtdocs")

        install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cutelystforms.qch
            DESTINATION ${DOCS_QTDOCSDIR}
            COMPONENT docs
            OPTIONAL
        )
    endif(DOXYGEN_QHG_LOCATION)

    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/htmldocs/
        DESTINATION ${DOCS_QTDOCSDIR}/cutelyst4forms
        COMPONENT docs
        OPTIONAL
    )

    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cutelystforms.tags
        DESTINATION ${DOCS_QTDOCSDIR}/cutelyst4forms
        COMPONENT devel
        OPTIONAL
    )
endif (BUILD_DOCS)
