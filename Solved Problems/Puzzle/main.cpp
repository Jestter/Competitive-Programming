#include <bits/stdc++.h>

using namespace std;

struct Equation{
    unordered_map<string,long long> quant;
    long long goal;
    long long extra_weight = 0;

    bool operator<(const Equation& other)const
    {
        //return quant.size()-extra_weight>other.quant.size()-other.extra_weight;

        return (quant.size()>other.quant.size()?true:(quant.size()==other.quant.size()
            && extra_weight>other.extra_weight?true:false));
    }

};

ostream& operator<<(ostream& o,const Equation& eq)
{
    for (unordered_map<string,long long>::const_iterator it = eq.quant.begin(); it != eq.quant.end(); ++it)
    {
        o << it->first << " x " << it->second << endl;
    }
    o << "goal = " << eq.goal << endl << endl;
    o << "extra_weight = " << eq.extra_weight << endl;
    return o;
}

int main()
{
    ios::sync_with_stdio(false);
    int L,C;
    while(cin >> L)
    {
        cin >> C;
        priority_queue<Equation> Q;
        map<string,long long> solved;

        string ss[L][C];

        Equation veqs[C];
        for (int i = 0; i < L; ++i)
        {
            Equation eq;
            for (int j = 0; j < C; ++j)
            {
                string k;
                cin >> k;
                ss[i][j]=k;
                eq.quant[k] = eq.quant[k]+1;
                veqs[j].quant[k] = eq.quant[k]+1;
            }
            cin >> eq.goal;
            Q.push(eq);
        }

        for (int i = 0; i < C; ++i)
        {
            cin >> veqs[i].goal;
            Q.push(veqs[i]);
        }

        while(!Q.empty())
        {
            Equation eq = Q.top();
            Q.pop();

        
            for(map<string,long long>::const_iterator it = solved.begin(); it!= solved.end(); ++it)
            {
                eq.goal -= (eq.quant[it->first]) * (it->second);
                eq.quant.erase(it->first);
                if(eq.quant.size()==1)break;
            }


            if(eq.quant.size()==1)
            {
                solved[eq.quant.begin()->first] = eq.goal/(eq.quant.begin()->second);
                
            }
            else if(eq.quant.size()>1)
            {
                eq.extra_weight+=1;
                Q.push(eq);
            }
        }

        for(map<string,long long>::const_iterator it = solved.begin(); it!=solved.end();++it)
        {
            cout << it->first << " " << it->second << endl;
        }
        
    }
    return 0;
}