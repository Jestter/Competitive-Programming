
import java.util.ArrayList;




public class InputGen
{
    public static void main(String[] args)
    {
        if(args.length==0)System.out.println("Faltan argumentos. P x1 x2 x3 x4 ... xn entrega todas las permutaciones de la lista. N x entrega x inputs aleatorios.");
        else if(args[0].equals("P"))
        {
            ArrayList<Integer> L = new ArrayList<Integer>();
            for (int i = 1; i < args.length; i++)
            {
                L.add(Integer.parseInt(args[i]));
            }
            new InputGen(L);
        }
        else if(args[0].equals("N"))
        {
            int a = Integer.parseInt(args[1]);
            new InputGen(a);
        }
       
    }

    public InputGen(int a)
    {
        for (int i = 0; i < a; i++)
        {
            String s ="";
            int b = (int) (Math.random()*29+1);
            for (int j = 0; j < b; j++)
            {
                int c = (int) (Math.random()*99+1);
                s = s + " "+c;
            }
            System.out.println(s.trim());
        }
        
    }
 
    
    public InputGen(ArrayList<Integer> L)
    {
        permute(L,"");  
    }
   
    
    public void permute(ArrayList<Integer> L,String s)
    {
        if(L.size()==0)
        {
            System.out.println(s.trim());
            return;
        }
        
        for (int i = 0; i < L.size(); i++)
        {
            String s2 = s+" "+L.get(i);
            ArrayList<Integer> auxL= (ArrayList<Integer>) L.clone();
            auxL.remove(i);
            permute(auxL,s2);
        }
 
    }
    
    
    
}