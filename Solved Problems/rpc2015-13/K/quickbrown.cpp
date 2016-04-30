#include <bits/stdc++.h>

using namespace std;


int main()
{
    int TC;
    char A[26];
    scanf("%d\n",&TC);
    while(TC--)
    {
    	memset(A,0,sizeof(A));
    	string s;
    	getline(cin,s);
    	for (int i = 0; i < s.length(); ++i)
    	{
    		if(s[i]>='a' && s[i]<='z')
    		{
    			A[s[i]-'a']=1;
    		}
    		if(s[i]>='A' && s[i]<='Z')
    		{
    			A[s[i]-'A']=1;
    		}
    	}
    	string res = "";
    	for (int i = 0; i < 26; ++i)
    	{
    		if(A[i]==0)
    		{
    			res+= ((char)(i+'a'));
    		}
    	}

    	if(res.length()!=0)printf("missing %s",res.c_str());
    	else printf("pangram");
    	if(TC>0)printf("\n");
    }
    return 0;
}