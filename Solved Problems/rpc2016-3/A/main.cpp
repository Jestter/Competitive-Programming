#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s1,s2;
	while(getline(cin,s1))
	{
		getline(cin,s2);
		if(s1[0]!=s2[0])cout << "no"<<endl;
		else
		{
			int i=0,j=0;
		
			for (; i < s1.length(); ++i)
			{
				if(s1[i]==' ')
				{
					i++;
					for (; j < s2.length(); ++j)
					{
						if(s2[j]==' ')
						{
							j++;
							break;
						}
					}
					if(s1[i]!=s2[j])
					{
						cout << "no" << endl;
						break;
					}
				}
				if(i+1==s1.length())
				{
					cout << "yes" << endl;
				}
			}
		}
		
	}

	return 0;
}