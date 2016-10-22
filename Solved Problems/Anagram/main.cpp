//Uva 195
#include <bits/stdc++.h>

using namespace std;


bool comp (int i,int j)
{
	if(abs(i - j) == 'a'-'A')
	{
		return i<j;
	}
	else
	{
		if(i > 'Z') i = i - 'a' + 'A';
		if(j > 'Z') j = j - 'a' + 'A';
	}
	return i<j;
}


bool scomp (string s1,string s2)
{
	for (int i = 0; i < s1.length(); ++i)
	{
		if(s1[i]!=s2[i])return comp(s1[i],s2[i]);
	}
	return false;
}

int main()
{
	int tc;
	cin >> tc;
	string s;
	while(cin >> s)
	{
		vector<string> v;
		stable_sort(s.begin(), s.end());
		unordered_set<string> set_;
		do 
		{
			if(set_.count(s)>0)continue;
		    v.push_back(s);
		    set_.insert(s);
	  	}while ( std::next_permutation(s.begin(),s.end()));
	  	stable_sort(v.begin(),v.end(),scomp);
	  	
	  	for(string ss:v)
	  	{
	  		cout << ss << endl;
	  	}
	}
	return 0;
}