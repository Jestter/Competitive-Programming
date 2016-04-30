
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class c
{

    public static void main(String[] args) throws IOException 
    {
        int contA = 0, contB = 0;
        int A = 0, B = 0;
        
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        
        String input = bf.readLine();
        String[] input2 = input.split(" ");
        
        int N = Integer.parseInt(input2[0]);
        int S = Integer.parseInt(input2[1]);
        int J = Integer.parseInt(input2[2]);
        int D = Integer.parseInt(input2[3]);
        
        for (int i = 0; i < N; i++)
        {
            char tmre = (char) bf.read();
            if( tmre == 'A')
            {
                contA++;
            }
            else{ 
                contB++;
            }    
            if((contA - contB) >= D && contA >= J){ 
                A++; 
                contA = 0; 
                contB = 0;
            }
            else if((contA - contB) <= -D && contB >= J){ 
                B++; 
                contA = 0; 
                contB = 0;}
            if( A == S || B == S) break;
        }
        System.out.println(A+" "+B);
    }
    
}
