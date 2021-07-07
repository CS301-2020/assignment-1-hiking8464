#include "read.h"

char *Hiking_read_line(void)       //function used to read the command line
{
  int bufsize = 1024;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "allocation error\n"); 
    exit(EXIT_FAILURE);  
  }
  while (1) 
  {
    c = getchar();    // Reading a character from the line (input)
    // If we reach the end of file (EOF) then replace it with a null character and return.
    if (c == EOF || c == '\n')
    {
      buffer[position] = '\0';
      return buffer;
    } 
    else 
    {
      buffer[position] = c;
    }
    position++;
    // If we exceed the buffer size then we reallocate by using the below statements.
    if (position >= bufsize) 
    {
      bufsize += 1024;
      buffer = realloc(buffer, bufsize);
      if (!buffer) 
      {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}