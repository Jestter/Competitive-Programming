import java.util.*;

public class Main
{

	HashMap<String,Integer> discovered;
	HashMap<String,String> parents;
	HashMap<String, ArrayList<String> > grafo;
	HashMap<String, Integer> entryTime;
	int t;
	int contCycle;
	String iniCycle;

	public static void main(String[] args) 
	{
		new Main();
	}

	public Main()
	{
		Scanner sc = new Scanner(System.in);
		
		int words = Integer.parseInt(sc.nextLine());
		while(words > 0)
		{
			grafo = new HashMap<String,ArrayList<String>>();
			discovered = new HashMap<String,Integer>();
			String id = "";
			while(words > 0)
			{
				String agg = sc.nextLine();
				String[] agg2 = agg.split(" ");

				id = agg2[0];
				discovered.put(id,0);
				//System.out.println(words + " " + agg);
				grafo.put(id,new ArrayList<String>());
				for (int i = 1 ;i < agg2.length ; i++) 
				{
					grafo.get(id).add(agg2[i]);
				}
				words--;
			}
			
			String root = id;

			parents = new HashMap<>();
			contCycle = Integer.MAX_VALUE;
			t = 0;
			entryTime = new HashMap<String, Integer>();

			

			for(String s: grafo.keySet())
			{
				//System.out.println(s+" asdakldsnfa");
				if(discovered.get(s)==0)
				{
					parents.put(s,"0");
					DFS(s);
				}
			}

			System.out.println(contCycle+1);
			ArrayList<String> asd = new ArrayList<>();
			for (int i=0;i<contCycle+1 ;i++ ) {
				asd.add(iniCycle);
				iniCycle = parents.get(iniCycle);
			}
			Collections.sort(asd);
			for(int i = 0;i<asd.size();i++)
			{
				System.out.print(asd.get(i)+(i+1==asd.size()?"":" "));
			}
			System.out.println();
			words = Integer.parseInt(sc.nextLine());
		}
	}

	void DFS(String root)
	{
		discovered.put(root,1);
		entryTime.put(root,t++);
		//System.out.println(root + " " + (t-1));
	
		for (int j = 0 ;j < grafo.get(root).size() ; j++) 
		{
			String nodito = grafo.get(root).get(j); 

			if(discovered.get(nodito) == null)
			{
				discovered.put(nodito,0);
			}
			if(discovered.get(nodito) == 0)
			{
				parents.put(nodito,root);
				DFS(nodito);
			}
			else if(discovered.get(nodito) == 1)
			{
				int tiempoqlo = entryTime.get(root) - entryTime.get(nodito);
				if(tiempoqlo < contCycle)iniCycle = root;
				contCycle = (tiempoqlo < contCycle? tiempoqlo:contCycle);
				
			}
		}

		discovered.put(root,2);
	}
}
