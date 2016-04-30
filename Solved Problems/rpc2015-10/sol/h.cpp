#include <bits/stdc++.h>

using namespace std;

unsigned long sortNumber(string s)
{
	sort(s.begin(),s.end());
	unsigned long res;
	sscanf(s.c_str(),"%lu",&res);
	return res;
}

int main()
{
	string s;
	cin >> s;
	
	unsigned long agg = strtoul (s.c_str(), NULL, 0);
	long contadorQueMeCuenta = 0;
	while(agg>0)
	{
		string s2 = s;
		unsigned long a = sortNumber(s2);
		//cout << agg << " - " << a;
		agg = agg-a;
		//cout << " = " << agg << endl;
		s = to_string(agg);
		contadorQueMeCuenta++;
	}

	cout << contadorQueMeCuenta;
}