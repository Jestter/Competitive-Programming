
import java.io.BufferedReader;
import java.io.Reader;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jestter
 */
public class TwoSubstrings
{
    public static void main(String[] args)
    {
        new TwoSubstrings();
    }

    public TwoSubstrings()
    {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext())
        {
            String s = sc.nextLine();
            if(s.contains("ABAB")|s.contains("BABA")|s.contains("ABBAB")|s.contains("ABAAB"))System.out.println("YES");
            else if(s.contains("AB")&s.contains("BA"))
            {
                s=s.replaceAll("AB", " ");  
                if(s.contains("BA"))System.out.println("YES");
                else System.out.println("NO");
            }
            else System.out.println("NO");
        }
    }
    
    
}
