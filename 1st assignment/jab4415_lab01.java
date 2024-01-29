import java.io.File;

public class jab4415_lab01  
{
    public static void main(String args[])
    {
        File inFile = new File(".");
        System.out.println(dirSize(inFile));
    }       

    public static long dirSize(File inFile)
    {
        long size = 0;
        if(inFile.list() != null && inFile.isDirectory())
        {
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
