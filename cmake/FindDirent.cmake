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

# - Find Dirent library
# Find the Dirent includes
# This module defines
#  DIRENT_INCLUDE_DIR, where to find dirent.h
#  DIRENT_FOUND, If false, do not try to use Dirent.

find_path(DIRENT_INCLUDE_DIR
  NAMES dirent.h
  HINTS
    ENV DIRENT_DIR
  PATH_SUFFIXES
    include
  NO_DEFAULT_PATH
)

# Handle the QUIETLY and REQUIRED arguments and set DIRENT_FOUND to TRUE
# if all listed variables are TRUE.
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(DIRENT DEFAULT_MSG DIRENT_INCLUDE_DIR)

mark_as_advanced(DIRENT_INCLUDE_DIR)
