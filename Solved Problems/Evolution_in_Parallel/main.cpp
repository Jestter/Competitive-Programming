#include <bits/stdc++.h>

using namespace std;

bool comp(const string lhs,const string rhs)
{
    return lhs.length() < rhs.length();
}

bool ancestor(string a,string d)
{
    int pos=0;
    int count = 0;
    for (int i = 0; i < a.length(); ++i)
    {
        for (; pos < d.length(); ++pos)
        {
            if(a[i] == d[pos])
            {
                count++;
                pos++;
                break;          
            }
        }
    }

    return count == a.length();
}

int main()
{
    int n;
    while(scanf("%d\n",&n)!=EOF)
    {
        cout << "----------" << endl;
        string root;
        getline(cin,root);
        vector<string> fosils;
        fosils.push_back(root);
        for (int i = 0; i < n; ++i)
        {
            string fos;
            getline(cin,fos);
            fosils.push_back(fos);
        }

        sort(fosils.begin(),fosils.end(),ancestor);

        for (int i = 0; i < fosils.size(); ++i)
        {
            cout << fosils[i] << endl;
            /*cout << fosils[i] << " : " << (fosils[i].compare(root)==0?"root":"");
            for (int j = i+1; j < fosils.size(); ++j)
            {
                if(ancestor(fosils[i],fosils[j])){cout << fosils[j];break;}
            }
            cout << endl;*/
        }
    }
}