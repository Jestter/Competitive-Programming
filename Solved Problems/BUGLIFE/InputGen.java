




public class InputGen
{
    public static void main(String[] args)
    {
        if(args.length!=0)new InputGen(Integer.parseInt(args[0]));
       
    }

    public InputGen(int a)
    {
        System.out.println(a);
        for (int i = 0; i < a; i++)
        {
            int b = (int) (1+Math.random()*10);
            int c = (int) (1+Math.random()*10);
            System.out.println(b+" "+c);
            for (int j = 0; j < c; j++)
            {
                int d =(int)(1+Math.random()*b);
                int e = (int)(1+Math.random()*b);
                while(d==e)
                {
                    d = (int)(1+Math.random()*b);
                    e = (int)(1+Math.random()*b);
                }
                System.out.println(d+" "+e);
            }
            
        }
        
    }   
    
}