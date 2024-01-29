//Justin Barrett 
//1001924415
//C18
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

long dirSize(DIR *dp, FILE *fp);

int main()
{

    //init directory
    DIR *dp = opendir (".");
    FILE *fp = fopen(".","r");
    
    if (dp) printf("%ld",dirSize(dp,fp));
    
    return 0;
}

/*
function takes an input directory and a file pointer and returns directory size in bytes

the function then checks which one was NULL (distinguishes a file from a directory)
if the directory is null it checks if its a file
and if so, it will add its size to the final sum

if fp is null, it will recurse until there are no more files or directories to read
*/
long dirSize(DIR *dp, FILE *fp)
{
    long sum = 0;
    struct dirent *ep;
    
    //make sure the input is a directory (and also not an error)
    if(dp != NULL)
    {
        while (ep = readdir (dp))
        {
            if(strcmp(ep->d_name, ".") != 0 && strcmp(ep->d_name, "..") != 0)
            {
                sum += dirSize(opendir(ep->d_name), fopen(ep->d_name,"r"));
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