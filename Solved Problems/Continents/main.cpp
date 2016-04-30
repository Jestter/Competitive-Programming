#include <bits/stdc++.h>

using namespace std;

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

char grid[20][20];
int R,C;

// returns the size of CC
int floodfill(int r, int c, char c1, char c2) 
{ 
    if (r < 0 || r >= R) return 0;// outside grid
    if (grid[r][c] != c1) return 0; // does not have color c1
    int ans = 1;// adds 1 to ans because vertex (r, c) has c1 as its color
    grid[r][c] = c2;// now recolors vertex (r, c) to c2 to avoid cycling!
    for (int d = 0; d < 4; d++)
    ans += floodfill(r + dr[d], (C+c + dc[d])%C, c1, c2);
    return ans;// the code is neat due to dr[] and dc[]
}


int main()
{
    while(scanf("%d %d\n",&R,&C)!=EOF)
    {
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                scanf("%c",&grid[i][j]);
            }
            scanf("\n");
        }
        int x,y;
        scanf("%d %d",&y,&x);
        scanf("\n");

        char land = grid[y][x];
        floodfill(y,x,land,'.');

        int max = 0;
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if(grid[i][j]==land)
                {
                    int ff = floodfill(i,j,land,'.');
                    if(ff>max) max = ff;
                }
            }
        }
        printf("%d\n",max);
    }
    return 0;
}