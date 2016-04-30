/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jestter
 */
public class CountingSort
{
    public static void main(String[] args)
    {
        new CountingSort();
    }
    
    int pene=100000000;
    public CountingSort()
    {
        long n1 = System.nanoTime();
        int[] arreglo1=new int[pene];
        
        for (int i = 0; i < pene; i++)
        {
            arreglo1[i]=(int)(Math.random()*200000000);
          //  System.out.print(arreglo1[i]+" ");
        }
        //System.out.println("");
        int max=0,min=Integer.MAX_VALUE;
        for (int i = 0; i < pene; i++)
        {
            if (max<arreglo1[i])
            {
                max=arreglo1[i];
            }
            if (min>arreglo1[i])
            {
                min=arreglo1[i];
            }
        }
        
        int[] arreglo2 = new int[max-min+1];
        
        for (int i = 0; i < arreglo1.length; i++)
        {
            arreglo2[arreglo1[i]-min]++;
        }
        
        int index=0;
        
        for (int i = 0; i < arreglo2.length; i++)
        {
            for (int j = 0; j < arreglo2[i]; j++)
            {
                arreglo1[index]=i+min;
               // System.out.print((i+min)+" ");
                index++;
            }
        }
        
        System.out.println((System.nanoTime()-n1)/1000000);
        
    }
    
    
}
