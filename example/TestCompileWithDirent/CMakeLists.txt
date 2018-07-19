# ****************************************************************************
#  Project:  LibCMaker_Dirent
#  Purpose:  A CMake build script for Dirent library
#  Author:   NikitaFeodonit, nfeodonit@yandex.com
# ****************************************************************************
#    Copyright (c) 2017-2018 NikitaFeodonit
#
#    This file is part of the LibCMaker_Dirent project.
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published
#    by the Free Software Foundation, either version 3 of the License,
#    or (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#    See the GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program. If not, see <http://www.gnu.org/licenses/>.
# ****************************************************************************

cmake_minimum_required(VERSION 3.2)

project(LibCMaker_Dirent_Compile_Test C)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(cmr_PRINT_DEBUG ON)


#-----------------------------------------------------------------------
# Configure to find_package()
#-----------------------------------------------------------------------

# Set CMake's search path for find_*() commands.
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}")

if(ANDROID)
  list(APPEND CMAKE_FIND_ROOT_PATH "${CMAKE_INSTALL_PREFIX}")
endif()

# To use our FindDirent.cmake.
list(APPEND CMAKE_MODULE_PATH
  "${PROJECT_SOURCE_DIR}/cmake/LibCMaker_Dirent/cmake"
)


#-----------------------------------------------------------------------
# Set path to LibCMaker root
#-----------------------------------------------------------------------

set(LIBCMAKER_SRC_DIR "${PROJECT_SOURCE_DIR}/cmake/LibCMaker")
# Uncomment it if need functions from LibCMaker.
#list(APPEND CMAKE_MODULE_PATH "${LIBCMAKER_SRC_DIR}/cmake/modules")


#-----------------------------------------------------------------------
# Set vars for LibCMaker_Dirent
#-----------------------------------------------------------------------

# Standard CMake vars.
#set(BUILD_SHARED_LIBS ON)

# Vars to lib_cmaker_dirent().
set(DIRENT_lib_VERSION "1.23.1")
set(DIRENT_DOWNLOAD_DIR "${PROJECT_BINARY_DIR}")
set(DIRENT_UNPACKED_DIR "${PROJECT_BINARY_DIR}")
set(DIRENT_BUILD_DIR "${PROJECT_BINARY_DIR}/build_dirent")

set(COPY_DIRENT_CMAKE_BUILD_SCRIPTS ON)

set(DIRENT_DIR "${CMAKE_INSTALL_PREFIX}")
set(ENV{DIRENT_DIR} "${DIRENT_DIR}")

# Library specific vars and options.


#-----------------------------------------------------------------------
# Build and install the Dirent
#-----------------------------------------------------------------------

include(
  ${PROJECT_SOURCE_DIR}/cmake/LibCMaker_Dirent/lib_cmaker_dirent.cmake)

# Make compile, build and install the library at a config CMake phase.
lib_cmaker_dirent(
  VERSION ${DIRENT_lib_VERSION}
  DOWNLOAD_DIR ${DIRENT_DOWNLOAD_DIR}
  UNPACKED_DIR ${DIRENT_UNPACKED_DIR}
  BUILD_DIR ${DIRENT_BUILD_DIR}
)


#-----------------------------------------------------------------------
# find_package
#-----------------------------------------------------------------------

# Use newly got library.
find_package(Dirent REQUIRED)


#-----------------------------------------------------------------------
# Link to the library
#-----------------------------------------------------------------------

# Build test executables.

# Get an example sources from the lib sources.
set(lib_SRC_DIR
  "${HB_UNPACKED_DIR}/harfbuzz-${HB_lib_VERSION}/harfbuzz-${HB_lib_VERSION}/test"
)
set(lib_EXAMPLES_SRC_DIR ${lib_SRC_DIR}/examples)

add_executable(${PROJECT_NAME}
  ${lib_EXAMPLES_SRC_DIR}/ls.c
)

# Dirent
target_include_directories(${PROJECT_NAME} PRIVATE ${DIRENT_INCLUDE_DIR})
