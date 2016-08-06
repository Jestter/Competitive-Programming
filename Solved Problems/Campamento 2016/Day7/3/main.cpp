#include <bits/stdc++.h>

using namespace std;

struct wea
{
	map<char,wea*> misweas;
};

int main()
{
	long wds;
	while(cin >> wds)
	{
		vector<string> palas;
		map<char,wea*> elSuperMapaDeWeas;
		for (int i = 0; i < wds; ++i)
		{
			string wordo; cin >> wordo;
			palas.push_back(wordo);
			map<char,wea*> auxito* = &elSuperMapaDeWeas;
			for (char c:wordo)
			{
				if(auxito.count(c)==0){wea we;(auxito*)[c] = &we;}
				auxito = (auxito[c]*)->misweas;
			}
		}

		double agg = 0;
		for (string pal:palas)
		{
			map<char,wea*> aux = elSuperMapaDeWeas[pal[0]]->misweas;
			long count = 1;
			for (int i = 1; i < pal.length(); ++i)
			{
				if(aux.size() == 0)
					{cout << "qwe" << endl;break;}
				if(aux.size() > 1)
				{cout << "asd" << endl;
					count++;
				}
				aux = aux[pal[i]]->misweas;
			}
			agg += count;
		}
		agg /= palas.size();
		cout << agg << endl;
	}
}