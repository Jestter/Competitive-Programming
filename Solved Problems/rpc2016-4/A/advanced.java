import java.util.*;
import java.math.*;

public class advanced {
	
	public static void main(String[] args) 
	{
		
		new advanced();
	}
        
       
	public advanced() 
    {
            Scanner sc = new Scanner(System.in);
            while(sc.hasNext())
            {
            	String s= sc.nextLine();
            	if(s.length()==1&&s.charAt(0)=='0')break;
            	BigInteger bi = new BigInteger(s);
            	String res = bi.multiply(bi.add(new BigInteger("1"))).divide(new BigInteger("2")).pow(2).toString();
            	if(res.length()>10)res = res.substring(res.length()-10,res.length());
            	System.out.println(new BigInteger(res));
            }
	}

}
