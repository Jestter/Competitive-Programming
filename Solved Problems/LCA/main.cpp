#include <cstdio>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    int cases;
    scanf("%d",&cases);
    for (int C = 0; C < cases; ++C)
    {
    	int N;
    	scanf("%d",&N);
    	int parent[N];
    	memset(parent,0,sizeof(parent));
    	for (int padre = 0; padre < N; ++padre)
    	{
    		int q; scanf("%d",&q);
    		for (int hijo = 0; hijo < q; ++hijo)
    		{
    			int h;scanf("%d",&h);
    			parent[h]=padre+1;
    		}
    	}
    	printf("Case %d:\n", (C+1));
    	int queries; scanf("%d",&queries);
    	for (int i = 0; i < queries; ++i)
    	{
    		int a,b; scanf("%d",&a);scanf("%d",&b);
    		while(true)
    		{
    			if(a==b)
    			{
    				printf("%d\n",a);break;
    			}
    			if (parent[a]==b)
    			{
    				printf("%d\n",b);break;
    			}
    			if (parent[b]==a)
    			{
    				printf("%d\n",a);break;
    			}
    			if (parent[a]==parent[b])
    			{
    				printf("%d\n",parent[a]);break;
    			}
    			if (a>=b)
    			{
    				a = parent[a];
    			}
    			else
    			{
    				b = parent[b];
    			}
    		}
    	}
    }
    return 0;
}
