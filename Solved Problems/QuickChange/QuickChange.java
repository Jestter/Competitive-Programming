
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jestter
 */
public class QuickChange
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        for(int i=0;i<a;i++)
        {
            int dataset = sc.nextInt();
            int q = dataset/25;
            dataset = dataset%25;
            int d = dataset/10;
            dataset = dataset%10;
            int n = dataset/5;
            dataset = dataset%5;
            int p = dataset;
            System.out.println((i+1)+" "+q+" QUARTER(S),"+d+" DIME(S),"+ n+" NICKEL(S),"+p+" PENNY(S)");
            
        }
    }
}
