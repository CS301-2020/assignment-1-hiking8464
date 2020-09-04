#include "cd.h"


int Hiking_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "Hiking: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("Hiking");

    }
  }
  return 1;
}
