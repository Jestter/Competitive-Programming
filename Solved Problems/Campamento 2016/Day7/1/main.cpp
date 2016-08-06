#include <bits/stdc++.h>

#define max_xy 1030
using namespace std;

long tree[max_xy][max_xy];

void update(long x , long y , long val){
    long y1;
    while (x <= max_xy){
        y1 = y;
        while (y1 <= max_xy){
            tree[x][y1] += val;
            y1 += (y1 & -y1); 
        }
        x += (x & -x);
    }
}

long long read(long x,long y){ // return sum from 1,1 to x,y.
   long long sum= 0;         
     while(x){
          long y1 = y;
         while(y1){
             sum += tree[x][y1];
               y1 -= y1 & -y1;
        }
        x -= x & -x;
    }
  	return sum;
}

int main()
{
	
	long tc;
	scanf("%ld",&tc);
	while(tc--)
	{

		long tam;
		scanf("%ld",&tam);
		for (long i = 0; i < tam+2; ++i)
		{
			for (long j = 0; j < tam+2; ++j)
			{
				tree[i][j] = 0;
			}
		}

		while(true)
		{
			char s[4];
			scanf("%s",s);
			if(s[1] == 'E')
			{
				long x,y,num;
				scanf("%ld %ld %ld",&x,&y,&num);
				long long suma = read(x+1,y+1) + read(x,y) - read(x+1,y) - read(x,y+1);
				update(x+1,y+1, -(suma-num));
			}
			if(s[1] == 'U')
			{
				long x1,y1,x2,y2;
				scanf("%ld %ld %ld %ld",&x1,&y1,&x2,&y2);
				long long suma1 = read(x1,y1);
				long long suma2 = read(x1,y2+1);
				long long suma3 = read(x2+1,y1);
				long long suma4 = read(x2+1,y2+1);
				printf("%lld\n",(suma4+suma1-suma2-suma3));
			}
			if(s[1] == 'N')
			{
				break;
			}
		}
	}

}