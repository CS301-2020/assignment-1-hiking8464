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
#include "pwd.h"
#include "ls.h"
#include "cd.h"
#include "mkdir.h"
#include "cat.h"
#include "grep.h"
#include "read.h"
#include "parsing.h"

//implicit declarations of the functions used in this file
char *Hiking_read_line(void);         
char **Hiking_split_line(char *line);   
int Hiking_Inbuilt_Binaries(char **args);      
int Hiking_noof_functions();  
int Hiking_execute(char **args);
int strcmp();
char *strtok();


int main(int argc,char **argv)       // main funtion 
{  
    char *line;
    char **args;
    int status;
    do {
        printf("Hiking > > > ");
        line = Hiking_read_line();                        
        args = Hiking_split_line(line);
        status = Hiking_execute(args);
        free(line);
        free(args);
    } while (status);
    return EXIT_SUCCESS;
}


int Hiking_Inbuilt_Binaries(char **args)     // all inbuilt binaries are executed in this function using execvp()
{
  pid_t pid, wpid;
  int status;
  pid = fork();
  if (pid == 0) 
  {
    if (execvp(args[0], args) == -1)            // Child process
    {
      perror("error");
    }
    exit(EXIT_FAILURE);
  } 
  else if (pid < 0) 
    {
      perror("forking failed");    // Error forking
    } 
  else
    {
      do {
      wpid = waitpid(pid, &status, WUNTRACED);}                     // Parent process
      while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
  return 1;
}

int Hiking_exit(char **args);   //function declaration of exit command

char *strings_of_my_commands[] = {"cd","exit","pwd","ls","mkdir","grep","cat"};    //commands implemented by me


int Hiking_noof_functions()            
{  
  return sizeof(strings_of_my_commands) / sizeof(char *);          // to find the total commands implemented by me in a easy so that it gets updated every time we add command to string_of_my_commands array
}

int Hiking_execute(char **args)
{ 
  int x=0;
  while(args[x]!=NULL)
  {
    x++;
  }
  if(strcmp(args[x-1],"&")==0)
  {   int rc=fork();
    if (rc<0)                   // Error forking
    {
      printf("fork failed");             
      exit(0);
    }
    else if(rc==0)                         // Child process
    {   
        int i;
        if (args[0] == NULL) 
        {
          // An empty command was entered.             
          return 1;
        }
        args[x-1]=NULL;
        for (i = 0; i < Hiking_noof_functions()-2; i++)
        {
          if (strcmp(args[0], strings_of_my_commands[i]) == 0) 
          { 
            if (i==0)
             {
               Hiking_cd(args);
               return 1;
             }
             else if (i==1)
             {
               Hiking_exit(args);
               return 1;
             }
             else if (i==2)
             {
               Hiking_pwd();
               return 1;
             }
             else if (i==3)
             {
               Hiking_ls(args);
               return 1;
             }
             else if (i==4)
             {
               Hiking_mkdir(args);
               return 1;
             }
             else if (i==5)
             {
               Hiking_grep(args);
               return 1;
             }
             else if (i==6)
             {
               Hiking_cat(args);
               return 1;
             }
          }
        }
    }
  }
  else 
  {
      int i;
        if (args[0] == NULL) 
        {
          // the command which was entered is empty so args[0]=NULL.
          return 1;
        }
        
        for (i = 0; i < Hiking_noof_functions(); i++)
        {
          if (strcmp(args[0], strings_of_my_commands[i]) == 0)   //comapring the command (args[0]) with the keyword in the array strings_of_my_commands[i] to know which function must be implemented
          { 
             if (i==0)
             {
               Hiking_cd(args);
               return 1;
             }
             else if (i==1)
             {
               Hiking_exit(args);
               return 1;
             }
             else if (i==2)
             {
               Hiking_pwd();
               return 1;
             }
             else if (i==3)
             {
               Hiking_ls(args);
               return 1;
             }
             else if (i==4)
             {
               Hiking_mkdir(args);
               return 1;
             }
             else if (i==5)
             {
               Hiking_grep(args);
               return 1;
             }
             else if (i==6)
             {
               Hiking_cat(args);
               return 1;
             }
          }
        }
  }
  return Hiking_Inbuilt_Binaries(args);        // for running inbuilt binaries like ps etc.  
}

int Hiking_exit(char **args)   // exits from our shell 
{ exit(0);
  return 0;
}
