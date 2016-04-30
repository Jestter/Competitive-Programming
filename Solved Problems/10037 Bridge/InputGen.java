

class InputGen
{
    public static void main(String[] args)
    {
        new InputGen(Integer.parseInt(args[0]));
    }

    public InputGen(int a)
    {
        System.out.println(2);
        System.out.println("");
        System.out.println(a);
        for (int i = 0; i < a; i++)
        {
            System.out.println((int)(Math.random()*99+1));
        }
        System.out.println("");
        System.out.println(a);
        for (int i = 0; i < a; i++)
        {
            System.out.println((int)(Math.random()*99+1));
        }
    }
    
}