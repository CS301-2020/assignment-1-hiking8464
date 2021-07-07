#include "cat.h"

int Hiking_cat(char *argv[]) 
{
  FILE *file;
  int chr;
  int count;
  int j=0;
    int argno=0;
    while(argv[j]!=NULL)
    { argno += 1;
      j++;
    }
 
  for(count = 1; count < argno; count++) {
    if((file = fopen(argv[count], "r")) == NULL) {
      fprintf(stderr, "%s: %s : %s\n", argv[0], argv[count],
        strerror(errno));
    continue;
    }
    while((chr = getc(file)) != EOF)
      fprintf(stdout, "%c", chr);
    fclose(file);
  }
  printf("\n");
  return 1;
}