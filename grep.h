#ifndef GREP
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#define GREP


void match_pattern(char *argv[]);           // implicit declaration
int Hiking_grep(char *argv[]);                    // implicit declaration
 

#endif