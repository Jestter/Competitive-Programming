

import java.io.*;
import java.util.*;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jestter
 */
class DistributingBallotBoxes
{

    int[] cities;
    int urns;
    
    public boolean realizableMax(int n)
    {
        //System.out.println("--------------");
        //System.out.println("para n="+n);
        
        int uaux = urns;
        for (int i = 0; i < cities.length; i++)
        {
            if(Math.ceil((cities[i]/(double)n)) <= uaux) uaux=(int) (uaux-Math.ceil((cities[i]/(double)n)));
            //System.out.println(citys[i]+" se necesita "+Math.ceil((citys[i]/(double)n)));}
            else return false;
        }
        return true;
    }
    
    public int BSearch(int max)
    {
        int min=1;
        int num = max/2;
        int i =0;
        
        
        
        boolean b = realizableMax(num),c=realizableMax(num-1);
        
        
        while(!(b&&!c))
        {
            //System.out.println(">>>>>>>>>>><<");
            if(b)
            {
                max=num;
            }
            else
            {
                min=num;
            }
            num = min+(max-min)/2;
            
            b = realizableMax(num);
            c=realizableMax(num-1); 
            
            i++;
        }
        
        return num;
    }
    
    public DistributingBallotBoxes()
    {
        InputReader in 	= new InputReader(System.in);
        OutputWriter out = new OutputWriter(System.out);
        
        int n=0,i=0;
        urns=0;
        
        n = in.readInt();
        urns = in.readInt();
        while(n!=-1 && urns!=-1)
        {
            
            int maxppl=0;
            
            cities = new int[n];
            while(i<n)
            {
                int total = in.readInt();
                cities[i] = total;
                if(total > maxppl)maxppl =total;
                i++;
            }
            i=0;
            out.printLine(this.BSearch(maxppl));
        
            n = in.readInt();
            urns = in.readInt();
       
        }
        
        out.close();
    
    }
    
    
        
    public static void main(String[] args)
    {
        new DistributingBallotBoxes();
        
    }
    
}

class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
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

		public int readInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
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

		public String readString() {
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

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public String next() {
			return readString();
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}

class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(Object...objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}

		public void printLine(Object...objects) {
			print(objects);
			writer.println();
		}

		public void close() {
			writer.close();
		}

		public void flush() {
			writer.flush();
		}

		}

class IOUtils {

		public static int[] readIntArray(InputReader in, int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = in.readInt();
			return array;
		}

		}