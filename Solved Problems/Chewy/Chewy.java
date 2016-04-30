
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
public class Chewy
{
    public static void main(String[] args)
    {
        new Chewy();
    }

    public Chewy()
    {
        String s= new Scanner(System.in).nextLine();
        boolean b = false;
        boolean c = true;
        String s2="";
        for (int i = 0; i < s.length(); i++)
        {
            int x= Integer.parseInt(s.charAt(i)+"");
            if(x==0&c)
            {
                x=9;
                b=true;
            }
            else if(x>=5)
            {
                if(x==9&b)
                {
                    x=0;
                }
                else if(x<9)
                {
                    x=9-x;
                    b=true;
                }
            }
            else b=true;
            
            c=false;
            
            if(x==0&b)
            {
                s2=s2+x;
            }
            else if(x>0)s2=s2+x;
        }
        System.out.println(s2);
    }
    
    
}
