#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct SuffixArray {
  const int L;
  string s;
  vector<vector<int> > P;
  vector<pair<pair<int,int>,int> > M;

  SuffixArray(const string &s) : L(s.length()), s(s), P(1, vector<int>(L, 0)), M(L) {
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
      P.push_back(vector<int>(L, 0));
      for (int i = 0; i < L; i++)
    M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++)
    P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
    }
  }

  vector<int> GetSuffixArray() { return P.back(); }

  // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
  int LongestCommonPrefix(int i, int j) {
    int len = 0;
    if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
    i += 1 << k;
    j += 1 << k;
    len += 1 << k;
      }
    }
    return len;
  }
};

long long toCode(string s)
{
	long long mult = 1;
	long long res = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		res += s[i]*mult;
		mult = mult << 1;
	}
	return res;
}

int main()
{
    string s1;
    string s2;
    int enteroqlo;
    while (cin >> s1 >> s2 >> enteroqlo)
    {
      int s1l = s1.length();
      string s3 = s1+" "+s2;
      SuffixArray SA(s3);

      vector<int> v = SA.GetSuffixArray();

  		vector<int> v2(v.size(),0);
      for (int i = 0; i < v.size(); i++)
  		{
  			v2[v[i]] = i;
  		}
  		string res ="";
  		int max = 0;
  		long long last=0;
  		for (int i = 1; i < v2.size(); i++)
  		{
  			if((v2[i-1]<s1l && v2[i]>= s1l)||(v2[i]<s1l && v2[i-1]>= s1l))
  			{
  				int lcp = SA.LongestCommonPrefix(v2[i-1], v2[i]);
  				/*if(max < lcp)
  				{
  					max = lcp;
  					res = s3.substr(v2[i],lcp);
  					last = toCode(res);
  				}*/
  				 if(enteroqlo == lcp)
  				{
					enteroqlo = -1;
					break;
  					/*string s4 = s3.substr(v2[i],lcp);
  					long long curr = toCode(s4);
  					if(last != curr)
  					{
  						res = res+"\n"+s4;
  						last = curr;
  					}*/	
  				}
  			}	
  		}
  		if(enteroqlo!=-1) cout << "no" << endl;
      else cout << "yes" << endl;
    }
}
