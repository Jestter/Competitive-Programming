
import java.util.Scanner;

class Palindrome
{
    static String revert(String s)
    {
        String ss = "";
        for (int i = s.length()-1; i >= 0; i--)
        {
            ss = ss + s.charAt(i);
        }
        return ss;
    }
    
    static boolean isMirrored(String s)
    {
        String c = "AAE3EHHIIJLJMMOOS2STTUUVVWWXXYYZ5Z1188";
        for (int i = 0; i < (s.length()+1)/2; i++)
        {
            if(c.indexOf(s.charAt(i)) == -1||c.charAt(c.indexOf(s.charAt(i))+1) != s.charAt(s.length()-1-i))
            {
                return false;
            }
        }
        return true;
    }
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = "";
        while(sc.hasNextLine())
        {
            s = sc.nextLine();
            if(s.equals(revert(s)) && isMirrored(s))
                System.out.println(s+" -- is a mirrored palindrome.");
            else if(s.equals(revert(s)))
                System.out.println(s+" -- is a regular palindrome.");
            else if(isMirrored(s))
                System.out.println(s+" -- is a mirrored string.");
            else 
                System.out.println(s+" -- is not a palindrome.");
            System.out.println();
           
        }
    }
}
