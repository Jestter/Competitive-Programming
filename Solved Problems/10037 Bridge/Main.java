
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.InputMismatchException;



public class Main
{
    public static void main(String[] args)
    {
        new Main();
    }

    public Main()
    {
        InputReader reader = new InputReader(System.in);
        int a = reader.readInt();
        String nl= System.getProperty("line.separator");
        
        for (int i = 0; i < a; i++)
        {
            int b = reader.readInt();
            String solution = "";
            int count = 0;
            ArrayList<Integer> aL = new ArrayList<>();
            
            for (int j = 0; j < b; j++)
            {      
                int d = reader.readInt();
                aL.add(d);
            }
            
            Collections.sort(aL);
            
            Integer[] L = new Integer[aL.size()];
            aL.toArray(L);
            
            int last = L.length-1;
            
            while(true)
            {
                if(last==0)
                {
                    solution = solution+
                           nl+L[0];
                    count+=L[0];
                    break;
                }
                if(last==1)
                {
                    solution = solution+
                           nl+L[0]+" "+L[1];
                    count+=L[1];
                    break; 
                }
                
                if(L[0]+L[last-1]<2*L[1])
                {
                    solution = solution+
                            nl+L[0]+" "+L[last-1]+
                            nl+L[0]+
                            nl+L[0]+" "+L[last];
                    count+=(L[last-1]+L[0]+L[last]);
                    last-=2;
                    if(last>0)
                    {
                        solution = solution+ nl+L[0];
                        count+=L[0];
                    }
                    else break;
                }
                
                else
                {
                    solution = solution+
                            nl+L[0]+" "+L[1]+
                            nl+L[0]+
                            nl+L[last-1]+" "+L[last];
                    
                    count+=(L[1]+L[0]+L[last]);
                    last-=2;
                    if(last>0)
                    {
                        solution = solution+ nl+L[1];
                        count+=L[1];
                    }
                    else break;
                }

            }
            
            System.out.println(count+solution);
            if(i+1<a)System.out.println("");
        }
    }  
}

class InputReader 
{

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

    public InputReader(InputStream stream)
    {
        this.stream = stream;
    }

    public int read()
    {
        if (numChars == -1)
                throw new InputMismatchException();
        if (curChar >= numChars) {
                curChar = 0;
                try {
                        numChars = stream.read(buf);
                } catch (IOException e) {
                        throw new InputMismatchException();
                }
                if (numChars <= 0)
                        return -1;
        }
        return buf[curChar++];
    }

    public int readInt() 
    {
        int c = read();
        while (isSpaceChar(c))
                c = read();
        int sgn = 1;
        if (c == '-')
        {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                    throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String readString() 
    {
        int c = read();
        while (isSpaceChar(c))
                c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public boolean isSpaceChar(int c) 
    {
        if (filter != null)
                return filter.isSpaceChar(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public String next()
    {
        return readString();
    }

    public interface SpaceCharFilter
    {
        public boolean isSpaceChar(int ch);
    }
}

class OutputWriter 
{
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream)
    {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer)
    {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object...objects) 
    {
        for (int i = 0; i < objects.length; i++) 
        {
            if (i != 0)
                    writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine(Object...objects)
    {
        print(objects);
        writer.println();
    }

    public void close() 
    {
        writer.close();
    }

    public void flush()
    {
        writer.flush();
    }

}

class IOUtils 
{
    public static int[] readIntArray(InputReader in, int size) 
    {
            int[] array = new int[size];
            for (int i = 0; i < size; i++)
                    array[i] = in.readInt();
            return array;
    }
}