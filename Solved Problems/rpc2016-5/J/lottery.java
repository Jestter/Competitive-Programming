import java.util.Scanner;
import java.util.LinkedList;

public class lottery 
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		while(true)
		{
			int pepitoPos = sc.nextInt();
			if(pepitoPos == 0)
				break;

			pepitoPos--;
			int answer;
			for(answer = 0; answer<1000; answer++)
			{
				LinkedList<Integer> raffle = new LinkedList<>();
				for(int i = 0; i<100; i++)
				{
					raffle.add(i);
				}

				int pointer = 0; 
				boolean pepitoWinner = true;
				boolean clockwise = true;

				//Buscar ganador de la rifa
				while(raffle.size() > 1)
				{
					if(clockwise)
					{
						//System.out.println("P+A = "+(pointer+answer));
						pointer = (pointer+answer)%raffle.size();
						//System.out.println("P = "+pointer);
					}
					else
					{
						//System.out.println("P-A = "+(pointer-answer));
						pointer = (pointer-answer)%raffle.size();
						if(pointer<0)
							pointer = raffle.size()+pointer;
						//System.out.println("P = "+pointer);
					}

					if(raffle.get(pointer) == pepitoPos)
					{
						//System.out.println("GG pepito :c");
						pepitoWinner = false;
						break;
					}
					else
					{
						raffle.remove(pointer);
						if(!clockwise)
							pointer = (pointer-1);
						if(pointer<0)
							pointer = raffle.size()+pointer;
						//System.out.println(raffle);
						//pointer = (pointer+1)%raffle.size();
					}

					clockwise = !clockwise;
				}

				if(raffle.getFirst() != pepitoPos)
				{
					pepitoWinner = false;
				}

				if(pepitoWinner)
				{
					break;
				}
			}
			System.out.println(answer+1);
		}
	}
}