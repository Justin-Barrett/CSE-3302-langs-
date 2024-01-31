//Justin Barrett 
//1001924415
//C18
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

long dirSize(DIR *dp, FILE *fp, char currPath[512]);

int main()
{
    char name[512] = "./";
    DIR *dp = opendir (".");
    FILE *fp = fopen(".","r");
    printf("%ld",dirSize(dp,fp,name));
    
    return 0;
}

/*
function takes an input directory, a file pointer, a file/directory path, and returns directory size in bytes
---
the function then checks which one was NULL to distinguishes a file from a directory
if the directory is null it checks if its a file
and if so, it will add its size to the final sum

if fp is null, it will recurse until there are no more files or directories to read, updating currPath as it goes
*/
long dirSize(DIR *dp, FILE *fp, char currPath[512])
{
    long sum = 0;
    struct dirent *ep = NULL;
    
    //make sure the input is a directory
    if(dp != NULL)
    {
        //while loop for reading directory entries
        while (ep = readdir (dp))
        {
            //if not current or prev directory
            if(strcmp(ep->d_name, ".") != 0 && strcmp(ep->d_name, "..") != 0)
            {
                //directory path name
                char name[512] = "";
                strcat(name, currPath);
                strcat(name,ep->d_name);
                
                //reusing fp :D
                fp = fopen(name,"r");
                strcat(name,"/");

                sum += dirSize(opendir(name), fp, name);
            }
        }
        closedir(dp);
    }
    //if its not a directory, check and see if its a file
    else if(fp != NULL)
    {
        fseek(fp, 0L, SEEK_END);
        sum += ftell(fp);
        fclose(fp);
    }
    
    return sum;
}