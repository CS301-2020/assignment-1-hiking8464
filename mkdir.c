#include "mkdir.h"

int Hiking_mkdir(char* args[])
{
  int status;
struct stat st = {0};
      mkdir(args[1], 0777);
      return 1;
  
}