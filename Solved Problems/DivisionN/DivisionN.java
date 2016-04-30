
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jestter
 */
class DivisionN
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int i = sc.nextInt();
        while(i!=0)
        {
            int a = sc.nextInt();
            int b = sc.nextInt();
            for (int j = 0; j < i; j++)
            {
                String s = "";
                int c = sc.nextInt();
                int d = sc.nextInt();
                if(d>b) s="N";
                if(d<b) s="S";
                if(c>a) s=s+"E";
                if(c<a) s=s+"O";
                
                if(a==c || b == d) s = "divisa";
                System.out.println(s);       
            }
            i = sc.nextInt();
        }
    }
}
