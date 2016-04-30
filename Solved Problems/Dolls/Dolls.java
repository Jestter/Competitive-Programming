
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jestter
 */
class Doll implements Comparable
{
        public int w;
        public int l;
        public int h;
        public Doll contains;
        public Doll iscontainedBy;
                
        public Doll(int w,int l,int h)
        {
            this.w = w;
            this.l = l;
            this.h = h;
            this.contains = null;
            this.iscontainedBy = null;
        }
        
        public boolean isContained()
        {
            if(this.iscontainedBy!=null)
            {
                return true;
            }
            return false;
        }
        
        public boolean fits(Doll d)
        {
            if(w<d.w && h<d.h && l<d.l)
            {
                return true;
            }
            return false;
        }
        
        @Override
        public int compareTo(Object o)
        {
            return (this.w-((Doll)o).w)+(this.l-((Doll)o).l)+(this.h-((Doll)o).h);
        }
        
        public void RelocateIn(ArrayList<Doll> dools)
        {
            if(!this.isContained())
            for(Doll d2:dools)
                {
                    if(this.fits(d2))
                    {
                        if(d2.contains!=null)
                        {
                            if(d2.contains.fits(this))
                            {
                                Doll aux = d2.contains;
                                d2.contains = this;
                                this.iscontainedBy = d2;
                                this.contains = aux;
                                //System.out.println(d2.print()+"<-"+this.print()+"<-"+aux.print());
                                break;
                            }
                            else if(Math.abs(d2.contains.compareTo(d2)) > Math.abs(this.compareTo(d2)))
                            {
                                d2.contains.iscontainedBy = null;
                                Doll aux = d2.contains;
                                //System.out.println("free : "+d2.contains.w);
                                d2.contains = this;
                                this.iscontainedBy = d2;
                                //System.out.println(d2.print()+"-x-"+aux.print()+";"+d2.print()+"<-"+this.print());
                                aux.RelocateIn(dools);     
                                break;
                            }
                        }
                        else
                        {
                            d2.contains = this;
                            this.iscontainedBy = d2;
                            //System.out.println(d2.print()+"<-"+this.print());
                            break;
                        }
                    }
                }
        }
        
        public String print()
        {
            return ("("+w+" "+h+" "+l+")");
        }
        
        public void showAll()
        {
            System.out.print(this.print());
            if(this.contains != null) {
                System.out.print("<-");
                this.contains.showAll();
            }
        }
 }

public class Dolls
{
   
    
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int i = Integer.parseInt((in.nextLine()));
        
        while(i!=0)
        {
            int j = 0;
            ArrayList<Doll> dools = new ArrayList<Doll>();

            while(j<i)
            {
                int w = Integer.parseInt((in.next()));
                int l = Integer.parseInt((in.next()));
                int h = Integer.parseInt((in.next()));
            
                dools.add(new Doll(w, l, h));
                j++;
            }      
            int count = Integer.MAX_VALUE;
            Collections.sort(dools);
            for(Doll das:dools){
            for(Doll d :dools)
            {
                    d.RelocateIn(dools);
            }
            
            int c=0;
           // System.out.println("-----");
            for(Doll d:dools)
            {
                if(!d.isContained())
                {
                    c++;
                    /*d.showAll();
                    System.out.println();*/
                }
            }
            /*if(c == 31 )
            {
                try{Thread.sleep(1000*15);}
                catch(Exception ex){};
            }*/
            Collections.shuffle(dools);
            if(c < count)count = c;
            }
            System.out.println(count);
            
            i = Integer.parseInt((in.next()));
       }    
    }
}