#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    while(cin >> m >> n)
    {
    	pair<int,int> matrix[m][n]; // desde,valor

    	for (int i = 0; i < m; ++i)
    	{
    		for (int j = 0; j < n; ++j)
    		{
    			matrix[i][j] = make_pair(-1,0);
    			cin >> matrix[i][j].second;
    		}
    	}

    	for (int i = m-2; i >= 0; ++i)
    	{
    		for (int j = 0; j < n; ++j)
    		{
    			matrix[i][j].second += matrix[i+1][(j-1+n)%n].second;
    			matrix[i][j].first = (j-1+n)%n;
    			for (int k = 0; k <= 1; ++k)
    			{
    				if(matrix[i][j].second > matrix[i+1][(j+k+n)%n].second)
    				{
    					matrix[i][j].second = matrix[i+1][(j+k+n)%n].second;
    					matrix[i][j].first = (j+k+n)%n;
    				}
    			}
    		}
    	}
    	
    	int best = 1<<31;

    	for (int j = 0; j < n; ++j)
    	{
    		best = min(matrix[0][j].second,best);
    	}

    	cout << best << endl;	
    }
    
    return 0;
}
