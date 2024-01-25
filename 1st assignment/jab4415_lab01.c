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
    
    if (dp) printf("%ld",dirSize(dp,NULL));
    
    return 0;
}

/*
function takes an input directory and a file pointer

takes in a directory and a null file pointer when the function recurses, it checks to see
which one is null

if the directory is null it checks if its a file
and if so, it will add its size to the final sum

if fp is null, it will scan through all the directories
recursively the function is complete
*/
long dirSize(DIR *dp, FILE *fp)
{
    long sum = 0;
    struct dirent *ep;
    
    //make sure the input is a directory (and also not an error)
    if(dp != NULL)
    {
        printf("dp");
        while (ep = readdir (dp))
        {
            if(strcmp(ep->d_name, ".") != 0 && strcmp(ep->d_name, "..") != 0)
            {
                printf("%s",ep->d_name);
                sum += dirSize(opendir(ep->d_name), fopen(ep->d_name,"r"));
            }
        }
        closedir(dp);
    }
    //if its not a directory, check and see if its a file
    else if(fp != NULL)
    {
        printf("fp");
        fseek(fp, 0L, SEEK_END);
        sum += ftell(fp);
        fclose(fp);
    }
    
    return sum;
}