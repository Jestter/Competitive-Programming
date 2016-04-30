
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;



public class Main 
{
    int B = 33;
    
    public static void main(String[] args) throws IOException
    {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(bf.readLine());
        for (int i = 0; i < T; i++)
        {
            new Main(bf.readLine());
            if(i<T-1)System.out.println();
        }
        System.out.println();
    }
    
    public Main(String s)
    {
        s+="\0";
        SuffixArrayNaive sa = new SuffixArrayNaive(s);
//	for (int i = 0; i < s.length(); i++) {
//	    System.out.print(sa.A[i] + ",");
//	}
//	System.out.println();

	LCPArray lcp = new LCPArray(s, sa.A);
        int max = -1;
        int maxVal = -1;
	for (int i = 0; i <s.length(); i++) {
	    //System.out.print(lcp.H[i] + ",");
            if(maxVal<lcp.H[i])
            {
                max = i;
                maxVal = lcp.H[i];
            }
	}
        String res = s.substring(sa.A[max],sa.A[max]+maxVal);

        
        long hashRes = res.hashCode();
        int rep = 0;
        int i = 0;
        int j = res.length();
        while(j < s.length())
        {
            long hashSub = s.substring(i, j).hashCode();
            if(hashSub == hashRes)
                rep++;
            i++;
            j++;
        }
                
        
        if(res.isEmpty())System.out.print("No repetitions found!");
        else System.out.print(res+" "+rep);   
          
    }
    
    
    public class SuffixComparator implements Comparator {
    String s;

    public int compare(Object o, Object p) {
	String str1 = s.substring(((Integer) o).intValue());
	String str2 = s.substring(((Integer) p).intValue());
	return str1.compareTo(str2);
    }

    SuffixComparator(String str) {
	s = str;
    }
}

    public class SuffixArrayNaive {
        int len;
        int[] A;

        SuffixArrayNaive(String s) {
            len = s.length();
            SuffixComparator comp = new SuffixComparator(s);
            Integer[] suffixes = new Integer[len];
            for (int i = 0; i < len; i++) suffixes[i] = new Integer(i);
            Arrays.sort(suffixes, comp); // build suffix array the naive way
            A = new int[len];
            for (int i = 0; i < len; i++) A[i] = suffixes[i].intValue();
        }
    }

    public class LCPArray {
        int H[];

        LCPArray(String s, int[] A) {
            int l = s.length();
            H = new int[l];

            // build inverse suffix array I:
            int[] I = new int[l];
            for (int i = 0; i < l; i++) I[A[i]] = i;

            // build LCP:
            int h = 0; H[0] = 0;
            for (int i = 0; i < l; i++) {
                if (I[i] != 0) {
                    while (s.charAt(i+h) == s.charAt(A[I[i]-1]+h)) h++;
                    H[I[i]] = h--;
                    if (h < 0) h = 0;
                }
            }
        }
    }

}