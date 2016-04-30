
import java.math.BigInteger;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jestter
 */
class CountingPrimes
{
    public static int cPrimes(int n)
    {
        //System.out.print(n+": ");
        int contador=0;
        long i;
        long c;
        c=n;
        if(c%2 == 0) contador++;
        while(c%2 ==  0)
        {
          //  System.out.print(2+" ");
            c = c/2;
        }
        i=3;
        boolean asd = true;
        while(i<=(Math.sqrt(c)+1))
        {
            if(c%i ==0)
            {
                if(asd){ contador++;asd = false;}
            //    System.out.print(i+" ");
                c=c/i;
            }
            else{
                asd = true;
                i = i+2;
            }
        }
        if(c>1){contador++;}
            //System.out.println(c);}
        return contador;
    }
    
    public static void main(String[] args)
    {
        /*for (int i = 1; i <= 1E6; i++)
        {
            System.out.println(i+" : "+cPrimes(i));
        }
        */
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();//Integer.parseInt(sc.nextLine());
        boolean isRight = false;
        
        while(a != 0)
        {
            System.out.println(a+" : "+cPrimes(a));
            a = sc.nextInt();
        }
    }
}
