#include <bits/stdc++.h>

using namespace std;

typedef pair<long, long> ii;
typedef vector<ii> vii;
typedef vector<long> vi;

long INF = LONG_MIN;

vector<vii> AdjList;
vi marked;
long c,l;

long bfs2(long s)
{
    long mayor = s;
    vi d(c, INF);d[s] = 0;
    queue<long> q; q.push(s);
    while (!q.empty()) 
    {
        int u = q.front(); q.pop();
        marked[u]=1;
        for (int j = 0; j < (long)AdjList[u].size(); j++) 
        {
            ii v = AdjList[u][j];
            if (d[v.first] == INF) 
            {
                d[v.first] = d[u] + 1;
                if(d[v.first]>d[mayor])mayor = v.first;
                q.push(v.first);
            }
        }
    }
    return d[mayor];
}

long bfs1(long s)
{
    long mayor = s;
    vi d(c, INF);d[s] = 0;
    queue<long> q; q.push(s);
    while (!q.empty()) 
    {
        int u = q.front(); q.pop();
        marked[u]=1;
        for (int j = 0; j < (long)AdjList[u].size(); j++) 
        {
            ii v = AdjList[u][j];
            if (d[v.first] == INF) 
            {
                d[v.first] = d[u] + 1;
                if(d[v.first]>d[mayor])mayor = v.first;
                q.push(v.first);
            }
        }
    }
    return bfs2(mayor);
}



int main()
{
    scanf("%ld %ld",&c,&l);
    if(c == 1)
    {
        printf("0");
        return 0;
    }
    if(l==0)
    {
        printf("%d", c==2?1:2);
        return 0;
    }

    AdjList = vector<vii>(c,vii());
    marked = vi(c,INF);
    for (int i = 0; i < l; ++i)
    {
        long a,b;
        scanf("%ld %ld",&a,&b);
        AdjList[a].push_back(ii(b,0));
        AdjList[b].push_back(ii(a,0));
    }
    
    long g1=0,g2=0,max = 0;

    for (int i = 0; i < c; ++i)
    {
        if(marked[i]==INF)
        {
            long val = bfs1(i);
            max = val>max?val:max;
            val = ceil(val/2.0);
            if(val > g1){g2=g1;g1=val;}
            else if(val>g2) g2 = val;
        }
    }

    printf("%ld", (g1+g2+1)>max?(g1+g2+1):max);

    return 0;
}