




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
            System.out.println(b*2);
            for (int j = 0; j < b; j++)
            {
                System.out.println("UPD ADD "+(int)(Math.random()*10000+1));
                System.out.println("CON");
            }
            
        }
        
    }   
    
}