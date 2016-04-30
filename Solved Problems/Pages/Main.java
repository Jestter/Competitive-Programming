
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(in.readLine(),",");
        
        boolean[] pages = new boolean[1001];
        
        while(tk.hasMoreTokens())
        {
            pages[Integer.parseInt(tk.nextToken())]=true;
        }
        int iniSeq = 0;
        boolean inSeq = false;
        boolean coma2 = false;
        for (int i = 1; i < pages.length; i++)
        {
            if(pages[i] & !inSeq)
            {
                iniSeq = i;
                inSeq = true;
            }
            if(i==1000 & pages[i] & inSeq)
            {
                if(iniSeq == i)
                {
                    if(!coma2)
                    {
                        System.out.print(iniSeq);coma2=true;
                    }
                    else System.out.print(","+iniSeq);
                }
                else
                {
                    if(!coma2)
                    {
                        System.out.print(iniSeq+"-"+(i));coma2=true;
                    }
                    else System.out.print(","+iniSeq+"-"+(i));
                }
                inSeq=false;
            }
            if(!pages[i] & inSeq)
            {
                if(iniSeq == i-1)
                {
                    if(!coma2)
                    {
                        System.out.print(iniSeq);coma2=true;
                    }
                    else System.out.print(","+iniSeq);
                }
                else
                {
                    if(!coma2)
                    {
                        System.out.print(iniSeq+"-"+(i-1));coma2=true;
                    }
                    else System.out.print(","+iniSeq+"-"+(i-1));
                }
                inSeq=false;
            }
        }
    }
}
