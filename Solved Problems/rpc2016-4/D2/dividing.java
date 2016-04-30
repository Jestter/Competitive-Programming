import java.util.*;
import java.math.*;

public class dividing 
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			String s = sc.nextLine();
			BigInteger agg = new BigInteger(s,16);
			BigInteger f = agg.mod(new BigInteger("17"));
			if(f.equals(new BigInteger("0")))System.out.println("yes");
			else System.out.println("no");
		}
		
	}
        


}
