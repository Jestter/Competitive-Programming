
//package primos;


//Para compilar:
//   javac Primos.java

//Para ejecutar: 
//   java -Xms512M -Xmx2G Primos

public class Primos 
{
    public int contadorPrimos;
    public int limite;
    public boolean isPrime[];
    
    public Primos()
    {   long aux = System.nanoTime();
        this.contadorPrimos = 0;
        this.limite = 1000000000+1;
        this.isPrime = new boolean[this.limite];
        this.llenarArray();
        System.out.println(((System.nanoTime()-aux)/1000000000)+" s.");
    }
    
    private void llenarArray()
    {
        for(int i = 0 ; i < this.isPrime.length ; i++)
        {
            this.isPrime[i] = false;
        }
        
        isPrime[2] = true;
        isPrime[3] = true;
        
        long n;
        int raiz = (int) (Math.sqrt(this.limite))+1;
        for(int x = 1 ; x < raiz ; x ++ )
        {
            long a = x*x;
            for(int y = 1 ; y < raiz ; y++)
            {
                long b = y*y;
                n = 4*a + b;
                
                if( n <= this.limite && (n%12 == 1 || n%12 ==5))
                {
                    isPrime[(int)n]= !isPrime[(int)n];
                }
                
                n = 3*a + b;
                
                if(n <= this.limite && n%12 == 7)
                {
                    isPrime[(int)n]= !isPrime[(int)n];
                }
                
                n = 3*a - b;
                
                if( x > y && n <= this.limite && n%12 == 11)
                {
                    isPrime[(int)n]= !isPrime[(int)n];
                }
            }
        }
        
        for(int i = 5 ; i < raiz ; i++)
        {
            if(this.isPrime[i]==true)
            {
                int pow = (int)Math.pow(i, 2);
                for(int k = pow; k < this.limite ; k += pow)
                {
                    this.isPrime[k] = false;
                }
            }
           
        }
        
//        for(int a = 0 ; a < this.isPrime.length ; a++)
//        {
//            if(this.isPrime[a])
//            {
//                this.contadorPrimos++;  
//                //System.out.println(a);
//            }
//        }
//        
//        
//           
//        System.out.println(this.contadorPrimos);
        
        
//        for(int i = 5; i < 200 ; i++)
//        {
//            if(this.isPrime[i])
//            {
//               
//                System.out.println(i);
//                
//            }
//        }
           
    }
    
    public static void main (String[] args)
    {
        Primos pri = new Primos();
        boolean check = true;
//        for(int i=4;i<=1000000000;i+=2)
//        {
//            for(int j=0;j<pri.isPrime.length;j++)
//            {
//                if(pri.isPrime[j])if(pri.isPrime[i-j])
//                {
//                    //System.out.println("conjetura exitosa para "+i+" con numeros: "+j+" y "+(i-j));
//                    break;
//                    
//                }
//                else if(j+1==pri.isPrime.length)
//                {
//                    System.out.println("cago la wea conjetura1 qla");
//                    check = false;
//                }
//            }
//            if(!check)break;
//        }
//        
//        for(int i=5;i<=1000000000;i+=2)
//        {
//            if(pri.isPrime[i]);
//                //System.out.println(i+" es primo.");
//            else if(pri.isPrime[i-2]);
//                //System.out.println(i+" cumple con numeros "+2+" y "+(i-2));
//            else for(int j=3;j<pri.isPrime.length;j++)
//            {
//                boolean found = false;
//                if(pri.isPrime[j])
//                for(int k=j;k<pri.isPrime.length;k++)
//                {
//                    if(pri.isPrime[k])if((i-j-k)>0 && pri.isPrime[i-j-k])
//                    {
//                        found = true;
//                        //System.out.println("conjetura exitosa para "+i+" con numeros: "+j+" , "+k+" y "+(i-j-k));
//                        break;
//
//                    }
//                    else if(j+1==pri.isPrime.length && k+1==pri.isPrime.length)
//                    {
//                        System.out.println("cago la wea conjetura2 qla");
//                        check = false;
//                    }
//                }
//                if(found)break;
//            }
//            if(!check)break;
//        }
        
          pri.isPrime[0]=true;
          for(int i=7;i<=1000000000;i++)
          {
              int e=2;
              if(i==1000 || i==10000 || i==100000 || i == 1000000 || i==10000000 || i==100000000)
                  System.out.println("milestone: "+i);
              boolean found = false;
              for (int j = 0; j <= (int)i/e; j++)
              {
                  if(pri.isPrime[j])
                  for (int k = 0; k <= (int)i/e; k++)
                  {
                      if(pri.isPrime[k])
                      for (int l = 0; l <= (int)i/e; l++)
                      {
                          if(pri.isPrime[l])
                          for (int m = 0; m <= (int)i/e; m++)
                          {
                              if(pri.isPrime[m] && (i-m-l-k-j)!=m && 
                                      (i-m-l-k-j)!=l && (i-m-l-k-j)!=k && (i-m-l-k-j)!= j
                                      &&(i-m-l-k-j)>0 && pri.isPrime[i-m-l-k-j])
                              {
//                                  String s = "Se cumple para "+i+" con valores: "+j+" "+k+" "+l+" "+m+" "+(i-m-l-k-j);
//                                  s = s.replaceAll(" 0", "");
//                                  System.out.println(s);
                                  found = true;
                                  break;
                              }
                              else if(m+1==(int)i/e && l+1==(int)i/e && k+1==(int)i/e && j+1==(int)i/e)
                              {
                                  System.out.println("No se cumple conj 3.");
                                  check = false;
                              }
                              if(m==(int)i/2)e++;
                              if(m==0)m=l;
                          }
                          if(found)break;
                          if(l==(int)i/3)e++;
                          if(l==0)l=k;
                      }
                      if(found)break;
                      if(k==(int)i/4)e++;
                      if(k==0)k=j;
                  }
                  if(found)break;
              }
              if(!check)break;
          }
        
        
    }
    
    
    
}



