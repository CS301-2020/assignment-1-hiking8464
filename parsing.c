#include "parsing.h"

char **Hiking_split_line(char *line)      //function that splits the input line into command and arguements
{
  int bufsize = 64, position = 0;
  char **total_noof_words = malloc(bufsize * sizeof(char*));
  char *token;

  if (!total_noof_words) 
  {
    fprintf(stderr, "allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line," ");
  while (token != NULL)
  {
    total_noof_words[position] = token;
    position++;
    if (position >= bufsize) 
    {
      bufsize += 64;
      total_noof_words = realloc(total_noof_words, bufsize * sizeof(char*));
      if (!total_noof_words) 
      {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL," ");
  } 
  total_noof_words[position] = NULL;
  return total_noof_words;
}