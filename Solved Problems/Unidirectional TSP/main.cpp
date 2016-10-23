#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    while(cin >> m >> n)
    {
    	pair<int,int> matrix[m][n]; // 	desde,valor

    	for (int i = 0; i < m; ++i)
    	{
    		for (int j = 0; j < n; ++j)
    		{
    			matrix[i][j] = make_pair(-1,0);
    			cin >> matrix[i][j].second;
    		}
    	}

    	for (int i = n-2; i >= 0; --i)
    	{
    		for (int j = 0; j < m; ++j)
    		{
    			int val = matrix[(j-1+m)%m][i+1].second;
    			matrix[j][i].first = (j-1+m)%m;
    			
    			for (int k = 0; k <= 1; ++k)
    			{
    				if(val > matrix[(j+k+m)%m][i+1].second)
    				{
    					val = matrix[(j+k+m)%m][i+1].second;
    					matrix[j][i].first = (j+k+m)%m;
    				}

    				else if(val >= matrix[(j+k+m)%m][i+1].second
    					&& matrix[j][i].first > (j+k+m)%m)
    				{
    					val = matrix[(j+k+m)%m][i+1].second;
    					matrix[j][i].first = (j+k+m)%m;
    				}
    			}

    			matrix[j][i].second += val;
    		}
    	}

    	int best = matrix[0][0].second;
    	int bestidx = 0;
    	for (int j = 1; j < m; ++j)
    	{
    		if(best > matrix[j][0].second) {best = matrix[j][0].second;bestidx = j;}
    	}

		for (int i = 0; i < n; ++i)
		{
			cout << (bestidx+1) << (i+1==n?"":" ");
			bestidx = matrix[bestidx][i].first;
		}
		cout << endl;
		cout << best << endl;
    }
    
    return 0;
}
