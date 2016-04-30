
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.InputMismatchException;



class Main {
	
    public static void main(String[] args) 
    {
        new Main();
    }
        
       
    public Main() 
    {
        InputReader in = new InputReader(System.in);
        int C = in.readInt();
        for (int i = 0; i < C; i++)
        {
            int bugs = in.readInt();
            int rels = in.readInt();
            boolean[] G1 = new boolean[bugs+1];
            boolean[] G2 = new boolean[bugs+1];
            boolean b = false;
//            System.out.println("conf: "+bugs+" "+rels);
            int count = 0;
            for (int j = 0; j < rels; j++)
            {
                try{
                int b1 = in.readInt();
                int b2 = in.readInt();
//                    System.out.println("lee: "+b1+" "+b2);
                if(!G1[b1] & !G2[b1] & !G1[b2] & !G2[b2])
                {
                    if(count==1)
                    {
                        
                        System.out.println("Scenario #"+(i+1)+":");
                        System.out.println("Suspicious bugs found!");
                        b=true;
                        break;
                    }
                    G1[b1]=true;
                    G2[b2]=true;
                    count++;
                }
                if(G1[b1])
                {
                    if(G1[b2])
                    {
                        System.out.println("Scenario #"+(i+1)+":");
                        System.out.println("Suspicious bugs found!");
                        b=true;
                        break;
                    }
                    else
                    {
                        G2[b2]=true;
                    }
                }
                else if(G2[b1])
                {
                    if(G2[b2])
                    {
                        System.out.println("Scenario #"+(i+1)+":");
                        System.out.println("Suspicious bugs found!");
                        b=true;
                        break;
                    }
                    else
                    {
                        G1[b2]=true;
                    }
                }
                else if(G1[b2])
                {
                    if(G1[b1])
                    {
                        System.out.println("Scenario #"+(i+1)+":");
                        System.out.println("Suspicious bugs found!");
                        b=true;
                        break;
                    }
                    else
                    {
                        G2[b1]=true;
                    }
                }
                else if(G2[b2])
                {
                    if(G2[b1])
                    {
                        System.out.println("Scenario #"+(i+1)+":");
                        System.out.println("Suspicious bugs found!");
                        b=true;
                        break;
                    }
                    else
                    {
                        G1[b1]=true;
                    }
                }
//                    for (int k = 1; k <= bugs; k++)
//                    {
//                        System.out.println(k+". "+G1[k]+" "+G2[k]);
//                    }
//                    System.out.println("------");
                }catch(Exception ex){}
            }
            if(!b)
            {
                boolean bb=true;
                for (int j = 1; j <= bugs; j++)
                {
                    if(!G1[j]&!G2[j])
                    {
                        System.out.println("Scenario #"+(i+1)+":");
                        System.out.println("Suspicious bugs found!");
                        bb = false;
                    }
                        
                }
                if(bb)
                {
                    System.out.println("Scenario #"+(i+1)+":");
                    System.out.println("No suspicious bugs found!");
                }
            }
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