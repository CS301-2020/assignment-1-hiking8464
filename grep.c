#include "grep.h"

void match_pattern(char *args[])
{
    int fd,r,j=0;
    char temp,line[100];
    if((fd=open(args[2],O_RDONLY)) != -1)
    {
        while((r=read(fd,&temp,sizeof(char)))!= 0)
        {
            if(temp!='\n')
            {
                line[j]=temp;
                j++;
            }
            else
            {
                if(strstr(line,args[1])!=NULL)
                    {
                        printf("%s\n",line);
                    }
                memset(line,0,sizeof(line));
                j=0;
            }

        }
    }   
}

int Hiking_grep(char *args[])
{
    struct stat stt;
    int j=0;
    int argno=0;
    while(args[j]!=NULL)
    { argno += 1;
      j++;
    }
    if(argno==3)
    {
        if(stat(args[2],&stt)==0)
            match_pattern(args);
        else 
        {
            perror("stat()");
            exit(1);
        }
    }
    return 1;
}