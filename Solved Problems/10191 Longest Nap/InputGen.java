/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jestter
 */
public class InputGen
{
    public static void main(String[] args)
    {
        new InputGen();
        
    }
    
    public String toString(int mins)
    {
        String hour = ""+mins/60;
        String min = ""+mins%60;
        if(min.length()==1)min="0"+min;
        return hour+":"+min;
    }
    
    public InputGen()
    {
        int cantidad = 600;
        
        for (int i = 0; i < cantidad; i++)
        {
            int quant = (int)(Math.random()*100);
            System.out.println(quant);
            for (int j = 0; j < quant; j++)
            {
                int ini = (int) (600+Math.random()*(8*60));
                int end;
                do{
                    end = (int) (600+Math.random()*(8*60));
                }while(end<ini);
                
                System.out.println(toString(ini)+" "+toString(end)+" input"+(i+1));
                
            }
            
        }
        
    }
    
    
}
