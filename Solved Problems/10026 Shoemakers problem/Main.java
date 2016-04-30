
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
        for (int i = 0; i < a; i++)
        {
            int b = reader.readInt();
            ArrayList<Work> aL = new ArrayList<>();
            for (int j = 0; j < b; j++)
            {
                int days = reader.readInt();
                int cents = reader.readInt();
                aL.add(new Work(j+1,days,cents));
            }
            Collections.sort(aL);
            String sol = "";
            for (Work w : aL)
            {
                sol=sol+" "+w.index;
            }
            System.out.println(sol.trim());
            if(i+1<a)
            {
                System.out.println("");
            }
        }
    }  
}

class Work implements Comparable
{
    int index;
    int days;
    int cents;

    public Work(int index, int days, int cents)
    {
        this.index = index;
        this.days = days;
        this.cents = cents;
    }
    
    @Override
    public int compareTo(Object o)
    {
        Work w2 = (Work)o;
        if(this.cents*w2.days > w2.cents*this.days)
        {
            return -1;
        }
        if(this.cents*w2.days < w2.cents*this.days)
        {
            return 1;
        }
        if(this.index < this.index)
        {
            return -1;
        }
        else return 1;
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