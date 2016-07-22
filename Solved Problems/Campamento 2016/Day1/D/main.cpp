#include <bits/stdc++.h>

using namespace std;

struct Cylinder{
	double x,y,r;
	Cylinder(double x,double y,double r):x(x),y(y),r(r){}
};

double dist(Cylinder a,Cylinder b)
{
	if(a.r > b.r)
	{
		double h = a.r -b.r;
		double hipo = a.r + b.r;
		return sqrt(hipo*hipo-h*h);
	}
	else
	{
		double h = b.r -a.r;
		double hipo = a.r + b.r;
		return sqrt(hipo*hipo-h*h);
	}
}

int main()
{
	int cyls;
	while(scanf("%d",&cyls)!=EOF)
	{
		vector<Cylinder> C;
		double maxW = 0;
		for (int i = 0; i < cyls; ++i)
		{
			int rad; scanf("%d",&rad);
			Cylinder nuevo(rad,rad,rad);
			if(C.size()==0)// || rad > maxW)
			{
				/*nuevo.x = rad;
				maxW = rad+rad;
				cout << "max: " << maxW<<endl;*/
				maxW = rad+rad;
				//cout << "max: " << maxW<<endl;
				C.push_back(nuevo);
				continue;
			}

			double maxX = rad;
			for (Cylinder cc:C)
			{
				double distx = dist(cc,nuevo);
				if(cc.x + distx > maxX)maxX=cc.x+distx;
			}
			nuevo.x = maxX;
			if(nuevo.x+rad > maxW){maxW = nuevo.x+rad;}//cout << "max: " << maxW<<endl;}
			C.push_back(nuevo);
		}
		printf("%.8f\n",maxW);

	}

	return 0;
}