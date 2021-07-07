#include "pwd.h"

int Hiking_pwd() 
{
    char cwd[1024];
    chdir("/path/to/change/directory/to");
    getcwd(cwd, sizeof(cwd));
    printf("Current working directory: %s\n", cwd);
    return 1;
}