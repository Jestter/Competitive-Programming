
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
public class C
{
    
    public static BigInteger superFunction(int potencia)
    {
        if(potencia == 0)return new BigInteger("1");
        BigInteger k = new BigInteger("2");
        for (int i = 2; i <= potencia; i++)
        {
            k = k.multiply(new BigInteger("2")).add((new BigInteger("2")).pow(i-1)).subtract(new BigInteger("1"));
        }
        return k;
    }6
    
    public static BigInteger unos(String bin)
    {
        if(bin.equals("0")) return new BigInteger("0");
        BigInteger sum = new BigInteger("0");
        int sumaUnosAdicionales = 0;
        while(bin.contains("1"))
        {
            sum = sum.add(superFunction(bin.length()-1-bin.indexOf("1")));
            sum = sum.add(new BigInteger("2").pow(bin.length()-1-bin.indexOf("1")).multiply(new BigInteger(""+sumaUnosAdicionales)));
            sumaUnosAdicionales++;
            bin = bin.replaceFirst("1", "0");
        }
        
        return sum;
    }
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = new BigInteger("2").pow(100).toString();//sc.nextLine(); 
        //System.out.println(s);
        //s = sc.nextLine();
        long ini = System.nanoTime();
        BigInteger a = new BigInteger("0");//new BigInteger(s.split(" ")[0]).subtract(new BigInteger("1"));
        BigInteger b = new BigInteger(s);//new BigInteger(s.split(" ")[1]);
        String sa = a.toString(2);
        String sb = b.toString(2);
      
        System.out.println(unos(sb).subtract(unos(sa)));
        System.out.println((System.nanoTime()-ini)/1000000);
       
        
    }
}
