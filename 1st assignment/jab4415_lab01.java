import java.io.File;

public class jab4415_lab01  
{
    public static void main(String args[])
    {
        File inFile = new File(".");
        System.out.println(dirSize(inFile));
    }       


    /*
    takes in an input File or Directory, and outputs its size
    
    if input is a directory it will run recursively for all entries
    adding to the size variable until the functionc ompletes
    
    if input is a file it will simply set the size variable

    function returns the size variable

    */
    public static long dirSize(File inFile)
    {
        long size = 0;
        //code for determining if input is a file or a directory
        if(inFile.list() != null && inFile.isDirectory())
        {
            //scans the directory
            for(int x=0; x<inFile.list().length; x++)
            {
                size += dirSize(new File(inFile.getName() + "/" + inFile.list()[x]));
            }
        }
        else if(inFile.isFile())
        {
            size = inFile.length();
        }
        return size;
    }
}
