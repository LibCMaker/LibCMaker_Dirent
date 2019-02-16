/*****************************************************************************
 * Project:  LibCMaker_STLCache
 * Purpose:  A CMake build script for STLCache library
 * Author:   NikitaFeodonit, nfeodonit@yandex.com
 *****************************************************************************
 *   Copyright (c) 2017-2019 NikitaFeodonit
 *
 *    This file is part of the LibCMaker_STLCache project.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published
 *    by the Free Software Foundation, either version 3 of the License,
 *    or (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *    See the GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program. If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

// The code is based on the code from
// <dirent>/examples/ls.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "gtest/gtest.h"

/*
 * List files and directories within a directory.
 */
static void
list_directory(
    const char *dirname)
{
  DIR *dir;
  struct dirent *ent;

  /* Open directory stream */
  dir = opendir (dirname);
  if (dir != NULL) {

    /* Print all files and directories within the directory */
    while ((ent = readdir (dir)) != NULL) {
      switch (ent->d_type) {
        case DT_REG:
          printf ("%s\n", ent->d_name);
          break;

        case DT_DIR:
          printf ("%s/\n", ent->d_name);
          break;

        case DT_LNK:
          printf ("%s@\n", ent->d_name);
          break;

        default:
          printf ("%s*\n", ent->d_name);
      }
    }

    closedir (dir);

  } else {
    /* Could not open directory */
    printf ("Cannot open directory %s\n", dirname);
    exit (EXIT_FAILURE);
  }
}

TEST(Examle, test)
{
  /* List current working directory */
  list_directory (".");

  EXPECT_TRUE(true);
}
