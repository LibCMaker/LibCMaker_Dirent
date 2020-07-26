# ****************************************************************************
#  Project:  LibCMaker_Dirent
#  Purpose:  A CMake build script for Dirent library
#  Author:   NikitaFeodonit, nfeodonit@yandex.com
# ****************************************************************************
#    Copyright (c) 2017-2019 NikitaFeodonit
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

#-----------------------------------------------------------------------
# The file is an example of the convenient script for the library build.
#-----------------------------------------------------------------------

#-----------------------------------------------------------------------
# Lib's name, version, paths
#-----------------------------------------------------------------------

set(DIRENT_lib_NAME "Dirent")
set(DIRENT_lib_VERSION "1.23.1" CACHE STRING "DIRENT_lib_VERSION")
set(DIRENT_lib_DIR "${CMAKE_CURRENT_LIST_DIR}" CACHE PATH "DIRENT_lib_DIR")

# To use our Find<LibName>.cmake.
list(APPEND CMAKE_MODULE_PATH "${DIRENT_lib_DIR}/cmake/modules")


#-----------------------------------------------------------------------
# LibCMaker_<LibName> specific vars and options
#-----------------------------------------------------------------------

option(COPY_DIRENT_CMAKE_BUILD_SCRIPTS "COPY_DIRENT_CMAKE_BUILD_SCRIPTS" ON)


#-----------------------------------------------------------------------
# Library specific vars and options
#-----------------------------------------------------------------------


#-----------------------------------------------------------------------
# Build, install and find the library
#-----------------------------------------------------------------------

cmr_find_package(
  LibCMaker_DIR   ${LibCMaker_DIR}
  NAME            ${DIRENT_lib_NAME}
  VERSION         ${DIRENT_lib_VERSION}
  LIB_DIR         ${DIRENT_lib_DIR}
  REQUIRED
)
