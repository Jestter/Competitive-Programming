
import java.util.Scanner;


public class vogons
{

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        int[][] Matrix = new int[N + 2][M];
        for (int i = 0; i < N ; i++)
        {
            for (int j = 0; j < M; j++)
            {
                Matrix[i+2][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < M; i++)
        {
            for (int j = 2; j < N+2 ; j++)
            {
                Matrix[j][i] = Math.max(Matrix[j-1][i], Matrix[j-2][i] + Matrix[j][i]);
            }
        }
        
        int[] solution = new int[M + 2];
        for (int i = 0; i < M; i++)
        {
            solution[i+2] = Matrix[N + 1][i];
        }
        
        for (int i = 2; i < M + 2; i++)
        {
            solution[i] = Math.max(solution[i-1], solution[i-2] + solution[i]);
        }
        System.out.println(solution[M+1]);
    }
    
}
