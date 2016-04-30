
import java.util.Scanner;



public class Main
{
    public static void main(String[] args)
    {
        new Main();
    }

    int size;
    int lock;
    int[] pancakes;
    
    public void flip(int index)
    {
        index = size-index;
        for (int i = 0; i < index; i++)
        {
            int aux = pancakes[i];
            pancakes[i] = pancakes[index];
            pancakes[index] = aux;
            index--;
        }
    }
    
    public boolean isSorted()
    {
        for (int i = 0; i < size-1; i++)
        {
            if(pancakes[i]>pancakes[i+1])return false;
        }
        return true;
    }
    
    public int findMaxElemIndex()
    {
        int index=-1;
        int max = 0;
        for (int i = 0; i < lock; i++)
        {
           if(pancakes[i]>max)
           {
               max=pancakes[i];
               index=i;
           }
        }
        return index;
    }
    
    public Main()
    {
        Scanner sc= new Scanner(System.in);
        while(sc.hasNextLine())
        {
            String s = sc.nextLine();
            Scanner sc2 = new Scanner(s);

            String flips="";
            pancakes = new int[30];
            size=0;
            
            while(sc2.hasNextInt()) pancakes[size++]=sc2.nextInt();
            
            lock = size;
            
            while(lock > 0)
            {
                int m = size-findMaxElemIndex();
                if(lock != findMaxElemIndex()+1)
                {
                    if(m!=size)
                    {
                        flip(m);
                        flips = flips+" "+(m);
                    }
                    flip(size-lock+1);
                    flips=flips+" "+(size-lock+1);
                }
                lock--;
            }
          
            System.out.println(s);
//            for (int i = 0; i < size; i++)
//            {
//                System.out.print(pancakes[i]+" ");
//            }
//            System.out.println("");
//            System.out.println("--------");
            System.out.println((flips+" 0").trim());
//            System.out.println("=========");
        }
    }
    
}