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

// The code is from
// <dirent>/examples/ls.c

/*
 * An example demonstrating basic directory listing.
 *
 * Compile this file with Visual Studio and run the produced command in
 * console with a directory name argument.  For example, command
 *
 *     ls "c:\Program Files"
 *
 * might output something like
 *
 *     ./
 *     ../
 *     7-Zip/
 *     Internet Explorer/
 *     Microsoft Visual Studio 9.0/
 *     Microsoft.NET/
 *     Mozilla Firefox/
 *
 * The ls command provided by this file is only an example: the command does
 * not have any fancy options like "ls -al" in Linux and the command does not
 * support file name matching like "ls *.c".
 *
 * Copyright (C) 2006-2012 Toni Ronkko
 * This file is part of dirent.  Dirent may be freely distributed
 * under the MIT license.  For all details and documentation, see
 * https://github.com/tronkko/dirent
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

static void list_directory (const char *dirname);


int
main(
    int argc, char *argv[])
{
  int i;

  /* For each directory in command line */
  i = 1;
  while (i < argc) {
    list_directory (argv[i]);
    i++;
  }

  /* List current working directory if no arguments on command line */
  if (argc == 1) {
    list_directory (".");
  }
  return EXIT_SUCCESS;
}

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
