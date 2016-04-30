#include <bits/stdc++.h>

typedef long long LL;
using namespace std;


double INF = 1e100;
double EPS = 1e-12;

struct PT
{
	double x,y;
	PT(){}
	PT(double x,double y):x(x),y(y){}
	PT(const PT &p):x(p.x),y(p.y){}
	PT operator + (const PT &p) const{return PT(x+p.x,y+p.y);}
	PT operator - (const PT &p) const{return PT(x-p.x,y-p.y);}
	PT operator * (double c) const{return PT(x*c,y*c);}
	PT operator / (double c) const{return PT(x/c,y/c);}
};

double ComputeSignedArea(const vector<PT> &p)
{
	double area = 0;
	for(int i=0;i<p.size();i++)
	{
		int j=(i+1)%p.size();
		area+= p[i].x*p[j].y - p[j].x*p[i].y;
	}
	return area/2.0;
}

double computeArea(const vector<PT> &p)
{
	return fabs(ComputeSignedArea(p));
}

int main()
{
	double a;
	int N;
	scanf("%lf %d",&a,&N);

	vector<PT> pts;
	for(int i=0;i<N;i++)
	{
		LL x,y;
		scanf("%lld %lld",&x,&y);
		pts.push_back(PT(x,y));
	
	}	
	
	double targetArea = computeArea(pts)*a;
	//printf("area: %lf ta: %lf\n",computeArea(pts),targetArea);

	pts.push_back(pts[0]);

	double min = 2,max = 1000;
	double s=500;
	while(true)
	{
		double s1 = 1/s;
		double s2 = 1-s1;
		vector<PT> pts2;
		for(int i=0;i<pts.size()-1;i++)
		{
			double x1 = pts[i].x+(pts[i+1].x-pts[i].x)*s1;
			double y1 = pts[i].y+(pts[i+1].y-pts[i].y)*s1;
			double x2 = pts[i].x+(pts[i+1].x-pts[i].x)*s2;
			double y2 = pts[i].y+(pts[i+1].y-pts[i].y)*s2;
			pts2.push_back(PT(x1,y1));
			pts2.push_back(PT(x2,y2));
		}
		double areaqla = computeArea(pts2);
		//printf("%lf %lf\n",s,areaqla);
		if(fabs(areaqla-targetArea)<0.001) break;
		else if(areaqla > targetArea) 
		{	
			max = s;
			s =min+(s-min)*0.5;
		}
		else if(areaqla < targetArea) 
		{
			min = s;
			s = min+(max-s)*0.5;
		}
		
	}

	printf("%.6f",s);

	return 0;
}
