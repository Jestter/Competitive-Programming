#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int c;
    scanf("%d",&c);
    for(int ii=0;ii<c;ii++)
    {
        int N;
        scanf("%d",&N);
        N=N+1;
        int* NN = (int*)malloc(sizeof(int)*N);
        fill(NN,NN+N,0);
        /*printf("--------\n");
        for(int i=0;i<N;i++)
        {
            printf("%d,",NN[i]);
        }
        printf("\n--------\n");*/
        int u;
        scanf("%d",&u);
        for(int i=0;i<u;i++)
        {
            int s,e,v;
            scanf("%d %d %d",&s,&e,&v);
            NN[s]+=v;
            NN[e+1]-=v;
        }
        /*printf("--------\n");
        for(int i=0;i<N;i++)
        {
            printf("%d,",NN[i]);
        }
        printf("\n--------\n");*/
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            int idx;
            scanf("%d",&idx);
            int sum=0;
            for(int j=0;j<=idx;j++)
            {
                sum+=NN[j];
            }
            printf("%d",sum);
            if(i+1<q)printf("\n");
        }
        free(NN);
        if(ii+1<c)printf("\n");
    }
}
