#include "ls.h"

int Hiking_ls(char* args[])
{
    DIR *mydir;
    struct dirent **myfile;        //constructing struct for files using dirent
    struct stat mystat;
    int noof_files;
    int i=0;
    int j=0;
    int argno=0;
    while(args[j]!=NULL)
    { argno += 1;
      j++;
    }
    
    if (argno==1)
    { noof_files=scandir(".",&myfile,NULL,alphasort);   // scandir gives us the total number of files in the directory from which we are going to list the files
      for(i;i<noof_files;i++)
      { 
         printf(" %s\n", myfile[i]->d_name);
      }
    }

    else if (argno>1)
    {
      for(int j=1;j<argno;j++)
      {  
          noof_files=scandir(args[j],&myfile,NULL,alphasort);
          for(int k=0;k<noof_files;k++)
          {
            printf(" %s\n", myfile[k]->d_name);
          }
      }
    }
    return 1;
}
