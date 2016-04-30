
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

//Solucion grafica a problema 10191 (uVa) : Longest fucking nap. SOLUCION DE WEBEO, PERO FUNCIONA!

public class Main
{
    public static void main(String[] args)
    {
        new Main();
    }

    //transforma una hora en formato hh:mm a su tiempo en minutos
    public int TimeToMin(String s)
    {
        int a;
        
        String[] ss = s.split(":");
        a = Integer.parseInt(ss[0])*60+Integer.parseInt(ss[1]);
        return a;
    }
    
    public Main()
    {
        Scanner sc = new Scanner(System.in);
        int casos = 1;
        
        while(sc.hasNext())
        {
            //relaciona cantidad de minutos con representacion en string
            //se puede hacer con calculos tambien pero meh. XD
            Map<Integer,String> map = new HashMap<Integer,String>(); 
            
            //se crea una imagen que luego se pintara segun intervalos en que no se pueda dormir :o
            BufferedImage img = new BufferedImage(1+(18-10)*60,1,BufferedImage.TYPE_3BYTE_BGR);
            Graphics2D g2d = img.createGraphics();
            g2d.setColor(Color.BLACK);
            //se pinta la imagen entera de negro (negro representa donde se puede dormir)
            g2d.fillRect(0, 0, 1+(18-10)*60, 1);
            g2d.setColor(Color.WHITE);
                        
            int lineNum=Integer.parseInt(sc.nextLine());
            map.put(0, "10:00");
            
            //se pintan los intervalos en que no se pueda dormir (blanco)
            for (int i = 0; i < lineNum; i++)
            {
                String s = sc.nextLine();
                int ini = TimeToMin(s.substring(0, 5));
                int end = TimeToMin(s.substring(6,11));
                map.put(end-600, s.substring(6,11));
                if(ini!=end)g2d.fillRect(ini-600, 0, (end-600)-(ini-600), 1);
            }
                        
            int start = 0;
            int longestNap=0;
            int ini=0;
            int end=0;
            boolean busy=true;
 
            //se busca el intervalo de color negro mas largo, que sera longest (fucking) nap
            for (int i = 0; i <= img.getWidth()-1; i++)
            {
                Color color = new Color(img.getRGB(i, 0));
                
                //detecta inicio de intervalo negro(nap)
                if(color.equals(Color.BLACK) & busy)
                {
                    
                    ini = i;
                    busy = false;
                }
                
                //detecta fin de intervalo negro(nap)
                if(color.equals(Color.WHITE) & !busy)
                {
                    
                    end=i+1;
                    if(end-ini>longestNap)
                    {
                        
                        start = ini;
                       
                        longestNap=end-ini;
                    }
                    busy=true;
                }
                if(i==img.getWidth()-1 & !busy)
                {
                    end=img.getWidth();
                    if(end-ini>longestNap)
                    {
                        start = ini;
                       
                        longestNap=end-ini;
                    }
                    busy=true;
                }
            }
            //cuando se hace la resta end-ini hay un minuto extra, en esta linea se soluciona.
            longestNap--;
            
            //finalmente se formatea la salida
            String finals = "";
            if(longestNap>=60) finals = (longestNap/60)+" hours and "+ (longestNap%60)+" minutes.";
            else finals = longestNap+" minutes.";
 
            System.out.println("Day #"+casos+": the longest nap starts at "+map.get(start)+" and will last for "+finals);
            casos++;
        }
    
    }
}
