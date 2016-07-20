import java.util.Scanner;
import java.math.*;

public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long cucaX = sc.nextInt();
		long cucaY = sc.nextInt();
		BigDecimal cucaSpeed = BigDecimal.valueOf(sc.nextLong()).multiply(BigDecimal.valueOf(sc.nextLong()));

		int n = sc.nextInt();
		double angleTotal = 0;
		while(n>0)
		{
			long circleX = sc.nextInt();
			long circleY = sc.nextInt();
			long radius = sc.nextInt();

			double dist = Math.sqrt(Math.pow(cucaX+circleX,2)+Math.pow(cucaY+circleY,2));
			if(dist <= radius)
			{
				angleTotal = 360;
				break;
			}
			else if(BigDecimal.valueOf(dist).compareTo(cucaSpeed.add(BigDecimal.valueOf(radius))) == -1)
			{
				double agg = Math.asin(BigDecimal.valueOf(dist).divide(cucaSpeed.multiply(BigDecimal.valueOf(2))).doubleValue());
				double alfa = 2*Math.toDegrees(agg);
				angleTotal += alfa;
			}
			n--;
		}
		System.out.println(angleTotal/360);
	}
}