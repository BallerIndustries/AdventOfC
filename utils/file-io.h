//
// Created by User on 27/10/2020.
//

#ifndef ADVENTOFC___FILE_IO_H
#define ADVENTOFC___FILE_IO_H

#include <cstdio>
#include <cstdlib>

char **readFileIntoArray(const char *filename);
char *readFile(const char *filename);
char **split(const char *pattern, char *text, int *__matchCount);

#endif //ADVENTOFC___FILE_IO_H
