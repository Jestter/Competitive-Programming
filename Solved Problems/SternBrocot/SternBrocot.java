
import java.util.ArrayList;
import java.util.GregorianCalendar;
import java.util.Scanner;

/**
 *
 * @author Jestter
 */
public class SternBrocot
{    
    public int GCD(int a, int b) 
    {
        if (b==0) return a;
        return GCD(b,a%b);
    }
   
    private class Tree
    {
        Fraction[] path;
        String sPath;
        
        public Tree(Fraction f)
        {
            sPath = "";
            ArrayList<Fraction> pathAux = new ArrayList<Fraction>();
            Fraction value = new Fraction(1,1);
            pathAux.add(value);
            Fraction l = new Fraction(0,1);
            Fraction r = new Fraction(1,0);
            //System.out.print(f.num+" "+f.den+" ");
            while(value.compareTo(f) != 0.0)
            {
               
                if(value.compareTo(f) > 0.0)
                {
                    //System.out.print("L");
                    sPath = sPath+"L";
                    r = value;
                    value = value.add(l);
                    
                }
                else
                {
                    //System.out.print("R");
                    sPath = sPath+"R";
                    l = value;
                    value = value.add(r);
                    
                }
                
                pathAux.add(value);
            }
            
            path = pathAux.toArray(new Fraction[pathAux.size()]);
        }
        
        public void printPath()
        {
            System.out.println(path[path.length-1].num+" "+path[path.length-1].den+" "+sPath);
        }
        
        private String line(int n)
        {
            String s="";
            for (int i = 0; i < n-1; i++)
            {
                s=s+"----";
            }
            s=s+"--";
            return s;
        }
        
        private String whiteSpace(int n)
        {
            String s="";
            for (int i = 0; i < n; i++)
            {
                s=s+" ";
            }
            return s;
        }
        
        public void showTreePath()
        {
            String[] ss = new String[(path.length*2-1)];
            char[] ca = sPath.toCharArray();
            for (int i = 0,j=0; i < ss.length; i=i+2)
            {
                if(j == ca.length)
                {
                    ss[i]=path[j].toString();
                }
                else if(j+1==ca.length)
                {
                    if(ca[j]=='R')
                    {
                        ss[i] = path[j].toString()+this.line(1)+"+";
                    }
                    else
                    {
                        ss[i] = "+"+this.line(1)+path[j].toString();
                    }
                }
                else if(ca[j]==ca[j+1])
                {
                    if(ca[j]=='R')
                    {
                        ss[i] = path[j].toString()+this.line(1)+"+";
                    }
                    else
                    {
                        ss[i] = "+"+this.line(1)+path[j].toString();
                    }
                }
                else
                {
                    if(ca[j]=='R')
                    {
                        ss[i] = path[j].toString()+this.line(ca.length-j)+"+";
                    }
                    else
                    {
                        ss[i] = "+"+this.line(ca.length-j)+path[j].toString();
                    }
                }
                if(i+1<ss.length)ss[i+1]="|";
                j++;
            }
            
            for (int i = 0; i < ss.length-1; i=i+2)
            {
                if(ss[i].indexOf("+") < ss[i+2].indexOf("/") && i+2<ss.length)
                {
                    int a = ss[i+2].indexOf("/");
                    for (int j = 0; j <= i; j++)
                    {
                        ss[j]= this.whiteSpace(a)+ss[j];
                    }
                }
                if(i+1<ss.length)
                {       
                    ss[i+1] = this.whiteSpace(ss[i].indexOf("+"))+ss[i+1];
                }
                if(i+2<ss.length)
                {
                    ss[i+2] = this.whiteSpace(ss[i+1].indexOf("|")-ss[i+2].indexOf("/"))+ss[i+2];
                }
            }
            
            for(String s : ss)
            {
                System.out.println(s);
            }
        }
        
                        
    }
    
    private class Fraction
    {
        public int num;
        public int den;
                
        public Fraction(int n,int d)
        {
            this.num = n;
            this.den = d;
        }
            
        public String toString() 
        {
            return this.num+"/"+this.den;
        }
        
        public Fraction add(Fraction f)
        {
            return new Fraction(this.num+f.num,this.den+f.den);
        }
        
        public Fraction makeIrreducible()
        {
           int aux = GCD(num,den);
           this.num = num/aux;
           this.den = den/aux;
           return this;
        }
              
        public double compareTo(Fraction f)
        {
            return ((double)this.num/this.den)-((double)f.num/f.den);
        }
    }
    
    public static void main(String[] args)
    {
        long a = System.currentTimeMillis();
        SternBrocot sb = new SternBrocot();
        sb.start();
        System.out.println(System.currentTimeMillis()-a);
    }

    public void start()
    {
        Scanner sc = new Scanner(System.in);
        
        int m = sc.nextInt();
        int n = sc.nextInt();
        int o = sc.nextInt()%2;
        while(m != n)
        {
            Tree tree = new Tree(new Fraction(m,n).makeIrreducible());
            tree.printPath();
            if(o == 1)tree.showTreePath();
            m = sc.nextInt();
            n = sc.nextInt();
            o = sc.nextInt()%2;
        }
    }
}
