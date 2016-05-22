import java.util.Scanner;

public class juanma
{

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        
        while(t > 0)
        {
            int n = sc.nextInt();
            int formulita = (((int)Math.pow(n, 4)) - (6*(int)Math.pow(n, 3)) + (23*((int)Math.pow(n, 2))) - (42*n) + 24)/24  + n;
            System.out.println(formulita);
            t--;
        }
        
    }
    
}
