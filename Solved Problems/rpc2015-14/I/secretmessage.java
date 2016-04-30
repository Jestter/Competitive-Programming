
import java.util.Scanner;

public class secretmessage 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        
        for(int i = 0; i<n; i++)
        {
            String message = sc.nextLine();
            int m = (int) Math.ceil(Math.sqrt(message.length()));
            String[] agg = new String[m];
            for(int j = 0; j<m; j++)
            {
                agg[j] = "";
            }
            
            for(int j = 0; j<message.length(); j++)
            {
                agg[j%m] = message.charAt(j) + agg[j%m] ;
            }
            
            for(int j=0; j<m; j++)
                System.out.print(agg[j]);
            System.out.println();
        }
    }
    
}
