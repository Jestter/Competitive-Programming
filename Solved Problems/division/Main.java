
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	boolean[] noprimos;
	
	public static void main(String[] args) {
		
		new Main();
	}
	
	public void inicriba()
	{
            noprimos[1]=true;
            for(int i=2;i<=10000;i++)
            {
                for(int j=2;i*j<=10000;j++)
                {
                    noprimos[i*j]=true;
                }
            }	
	}
	
        
        public static int gcd(int p, int q) 
        {
            while (q != 0) {
                int temp = q;
                q = p % q;
                p = temp;
            }
            return p;
        }
        
	public int GCD(ArrayList<Integer> L)
	{
		if(L.size()==0)return -1;
		if(L.size()==1)return L.get(0);
		
		int gcd = gcd(L.get(0),L.get(1));
		for(int i=2; i<L.size();i++)
		{
			gcd = gcd(gcd,L.get(i));
		}
		return gcd;
	}
	
	public Main() 
        {
            noprimos = new boolean[10001];
            inicriba();
            
            Scanner sc = new Scanner(System.in);
            int C = Integer.parseInt(sc.nextLine());
            for(int i=0;i<C;i++)
            {
                ArrayList<Integer> list = new ArrayList<Integer>();
                int N= Integer.parseInt(sc.nextLine());
                for(int j=0;j<N;j++)
                {
                    String l = sc.nextLine();
                    if(l.contains("ADD"))
                    {
                        int in = Integer.parseInt(l.split(" ")[2]);
                        if(noprimos[in])list.add(in);
                    }
                    if(l.contains("REM"))
                    {
                        list.remove(list.indexOf(Integer.parseInt(l.split(" ")[2])));
                    }
                    if(l.contains("CON"))
                    {
                        int gcd = GCD(list);
                        //System.out.println("gcd="+gcd);
                        if(gcd == -1) System.out.println(-1);
                        else
                        {
                            
                            String res = "";
                            for (int k = 1; k < gcd/2; k++)
                            {
                                //System.out.println(k +" "+ (gcd/(double)k));
//                                if(noprimos[k] & gcd%k==0)
//                                {
//                                    res = res.trim()+" "+k;
//                                    
//                                }
                                if(noprimos[gcd/k] & gcd%k==0)
                                {
                                    res = (gcd/k)+" "+res.trim();
                                }
                            }
                            System.out.println(res.isEmpty()?1:1+" "+res.trim());
                        }

                    }
                    //for(int h:list)System.out.println(h);
                }
            }
        //}catch(Exception ex){ex.printStackTrace();}
	}

}
