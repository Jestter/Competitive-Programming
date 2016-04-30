#include <bits/stdc++.h>
using namespace std;


#define REMOVE_REDUNDANT

typedef double T;
const T EPS = 1e-7;
struct PT { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }

  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  
#ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
#endif
}
double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }

PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

double DistancePointLine(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointLine(a, b, c)));
}

bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}

int main()
{
	int D,P,cases = 0;
	scanf("%d%d",&D,&P);
	while(D && P)
	{
		if(cases)printf("\n");
		cases++;
		int x1,x2,y1,y2;
		vector<PT> ptsD;
		for (int i = 0; i < D; ++i)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			ptsD.push_back(PT(x1,y1));
			ptsD.push_back(PT(x1,y2));
			ptsD.push_back(PT(x2,y1));
			ptsD.push_back(PT(x2,y2));
		}
		ConvexHull(ptsD);
		ptsD.push_back(ptsD[0]);
		vector<PT> ptsP;
		for (int i = 0; i < P; ++i)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			ptsP.push_back(PT(x1,y1));
			ptsP.push_back(PT(x1,y2));
			ptsP.push_back(PT(x2,y1));
			ptsP.push_back(PT(x2,y2));
		}
		ConvexHull(ptsP);
		ptsD.push_back(ptsP[0]);
		bool intersects = false;
		for (int i = 0; i < ptsD.size()-2; ++i)
		{
			PT a = ptsD[i],b = ptsD[i+1];
			for (int j = 0; j < ptsP.size()-2; ++j)
			{
				PT c = ptsP[j],d = ptsP[j+1];
				if(SegmentsIntersect(a,b,c,d))
				{
					intersects = true;
					break;
				}
			}
			if(intersects)break;
		}
		if(intersects) printf("Case %d: It is not possible to separate the two groups of vendors.\n",cases);
		else printf("Case %d: It is possible to separate the two groups of vendors.\n",cases);
		scanf("%d%d",&D,&P);
	}
		
    return 0;
}
