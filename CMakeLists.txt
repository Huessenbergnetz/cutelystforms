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

set(CUTELYST_VERSION_MAJOR 3)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Qml LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} 5.15.2 COMPONENTS Core Qml LinguistTools REQUIRED)
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

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/Cutelyst3Qt${QT_VERSION_MAJOR}FormsConfigVersion.cmake
    VERSION ${cutelystforms_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/CutelystForms-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}FormsConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Cutelyst${CUTELYST_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
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
