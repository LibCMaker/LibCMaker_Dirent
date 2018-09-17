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

cmake_minimum_required(VERSION 3.4)

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


#-----------------------------------------------------------------------
# Set path to LibCMaker root
#-----------------------------------------------------------------------

set(LibCMaker_DIR "${CMAKE_CURRENT_LIST_DIR}/cmake/LibCMaker")
# Uncomment it if need functions from LibCMaker
#list(APPEND CMAKE_MODULE_PATH "${LibCMaker_DIR}/cmake")


#-----------------------------------------------------------------------
# Set vars for LibCMaker_Dirent
#-----------------------------------------------------------------------

set(DIRENT_lib_NAME     "Dirent")
set(DIRENT_lib_VERSION  "1.23.1")
set(DIRENT_lib_DIR      "${CMAKE_CURRENT_LIST_DIR}/cmake/LibCMaker_Dirent")

# To use below for sample sources.
set(cmr_UNPACKED_DIR ${CMAKE_CURRENT_BINARY_DIR}/download/unpacked)

# To use our FindDirent.cmake.
list(APPEND CMAKE_MODULE_PATH "${DIRENT_lib_DIR}/cmake/modules")

set(COPY_DIRENT_CMAKE_BUILD_SCRIPTS ON)


#-----------------------------------------------------------------------
# Library specific vars and options
#-----------------------------------------------------------------------


#-----------------------------------------------------------------------
# Build, install and find the Dirent
#-----------------------------------------------------------------------

# Make build and install the library at a config CMake phase.
include(${LibCMaker_DIR}/cmake/cmr_find_package.cmake)
cmr_find_package(
  LibCMaker_DIR   ${LibCMaker_DIR}
  NAME            ${DIRENT_lib_NAME}
  VERSION         ${DIRENT_lib_VERSION}
  LIB_DIR         ${DIRENT_lib_DIR}
  REQUIRED
)


#-----------------------------------------------------------------------
# Link to the library
#-----------------------------------------------------------------------

# Build test executables.

# Get an example sources from the lib sources.
set(lib_SRC_DIR
  "${cmr_UNPACKED_DIR}/dirent-${DIRENT_lib_VERSION}/dirent-${DIRENT_lib_VERSION}"
)
set(lib_EXAMPLES_SRC_DIR ${lib_SRC_DIR}/examples)

add_executable(${PROJECT_NAME}
  ${lib_EXAMPLES_SRC_DIR}/ls.c
)

# Dirent
target_include_directories(${PROJECT_NAME} PRIVATE ${DIRENT_INCLUDE_DIR})
