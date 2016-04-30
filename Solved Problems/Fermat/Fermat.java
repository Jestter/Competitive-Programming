
import java.util.Scanner;

/**
 *
 * @author Jestter
 */
public class Fermat
{
    int[] triangulars;
    
    public boolean isTriangular(int k)
    {
        if(k==0) return true;
        double aux = k;
        double a= Math.ceil(Math.sqrt(2*k));
        double b= Math.floor(Math.sqrt(2*k));
        
        if(aux == a*b/2 && a!=b) return true;
        else return false;      
    }
    
    public int maxT(int k)//encuentra el maximo numero triangular menor al numero dado
    {
        double a= Math.ceil(Math.sqrt(2*k));
        double b= Math.floor(Math.sqrt(2*k));
        int m = (int) (a*b/2);
        if(k == 2) return 1;
        else if(m<=k)return m;
        else return (int) ((a-1)*(b-1)/2);
    }
    
    public boolean isPerfectSquare(int n)//los cuadrados perfectos estan formados por la suma de dos triangulares consecutivos
    {
        int root = (int) Math.sqrt(n);
        if(root*root == n) return true;
        else return false;
    }
    
    public int verify(int n)
    {
        if(isTriangular(n)||isPerfectSquare(n)||isTriangular(n/3))
        {   
            return 1; //el numero es triangular por lo tanto cumple
        }
        int a = maxT(n);
        for (int i = 0; this.triangulars[i] <= a; i++)
        {   
            if(isPerfectSquare(n-this.triangulars[i])||isTriangular((n-this.triangulars[i])/2))return 1;
            int b = maxT(n-this.triangulars[i]);   
            for (int j = i; this.triangulars[j] <= b; j++)
            {     
                  int k = n-this.triangulars[i]-this.triangulars[j];
                  if(isTriangular(k)&&(k>=this.triangulars[j]))
                  {
                       return 1; //encontro la combinacion de triangulares por lo tanto el numero cumple
                  }
                    
            }
            
        }
        return 0;//no encontro triangulares que cumplieran con la conjetura para este numero

    }
        
    public void printTriangulars(int n)
    {   
        if(isTriangular(n))
        {   
            System.out.println(n+": "+n);
            return;
        }
        int a = maxT(n);
        for (int i = 0; this.triangulars[i] <= a; i++)
        {   
            int b = maxT(n-this.triangulars[i]);    
            for (int j = i; this.triangulars[j] <= b; j++)
            {     
                  int k = n-this.triangulars[i]-this.triangulars[j];
                  if(isTriangular(k)&&(k>=this.triangulars[j]))
                  {
                       System.out.println((n+": "+(k)+" "+this.triangulars[j]+" "+this.triangulars[i]).replaceAll(" 0", ""));
                       
                       return;
                  }
                    
            }
            
         }
    }
    
    public void fillTri()//rellena la matriz con todos los numeros triangulares hasta T(44722) = 1000006281
    {
        for (int i = 0; i<44722; i++)
        {
            int c = i*(i+1)/2;
            this.triangulars[i] = c;         
        }
    }
    
    public static void main(String[] args)
    {
        Fermat fermat = new Fermat();
        fermat.fillTri();
        fermat.start();
        
    }
    
    public void start()
    {
        Scanner sc = new Scanner(System.in);
        
        int in = 0;
        
        do
        {
            
            in = Integer.parseInt(sc.nextLine());
            
            if(in == 0)
            {
                
                int aux = 1;
                
                for (int i = 1; i < 1E9; i++)
                {
                    
                    if(this.verify(i)== 0)
                    {
                        aux = 0;
                        System.out.println(0);
                        break;
                    }
                }
                if(aux == 1) System.out.println(1);
            }
            else
            {
                this.printTriangulars(in);
            }
            
            
        }while(in > -1);
    }
    
    public Fermat()
    {
        this.triangulars = new int[44722];
    }
}
