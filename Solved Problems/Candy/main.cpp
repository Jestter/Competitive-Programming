#include <bits/stdc++.h>

using namespace std;

int main()
{
	int rows,cols;
	scanf("%d %d",&rows,&cols);
	while(rows && cols)
	{
		int boxes[rows+2][cols+2]; //2 extra para simplificar el codigo
		memset(boxes,0,sizeof boxes);
		for (int i = 2; i < rows+2; ++i)
		{
			for (int j = 2; j < cols+2; ++j)
			{
				scanf("%d",&boxes[i][j]);
			}
		}

		/*Se hace DP sobre cada fila obteniendo el mayor numero de 
		dulces de cada una*/

		for (int i = 2; i < rows+2; ++i)
		{
			for (int j = 2; j < cols+2; ++j)
			{
				boxes[i][j] = max(boxes[i][j-1], boxes[i][j-2] + boxes[i][j]);
			}
		}

		/*Ahora la mayor cantidad de dulces de cada fila esta almacenada 
		en la ultima casilla de estas (cols+1).
		See busca obtener la mayor cantidad total haciendo 
		DP sobre el resultado de las filas*/

		for (int i = 2; i < rows+2; ++i)
		{
			boxes[i][cols+1] = max(boxes[i-1][cols+1], boxes[i-2][cols+1] + boxes[i][cols+1]);
		}

		printf("%d\n", boxes[rows+1][cols+1]);
		scanf("%d %d",&rows,&cols);
	}
}