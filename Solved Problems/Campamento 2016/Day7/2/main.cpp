#include <bits/stdc++.h>

using namespace std;

struct RollingHash
{
	string s;
	const long L;
	long long hashValue;
	long ini;
	long end;
	long long base;

	RollingHash(const string &s,long hlength):L(hlength),s(s),ini(0),end(L-1),hashValue(0)
	{
		base = 1;
		for (long i = L-1; i >= 0; --i)
		{
			//hashValue += (s[i])<<((L-1) - i);
			hashValue += s[i] * base;
			if(i!=0)base*=127;
		}
	}

	long long getHashValue(){return hashValue;}

	//returns the next hash value. If the last value is reached, next calls will return the last value.
	long long nextHashValue()
	{
		if(end == s.length()) return hashValue;
		hashValue -= (s[ini]) * base;//<< (L-1);
		hashValue*=127;
		hashValue+= (s[end+1]);
		ini++;
		end++;
		return hashValue;
	}

	void reset()
	{
		hashValue = 0;
		for (long i = 0; i < L; ++i)
		{
			hashValue += (s[i])<<((L-1) - i);
		}
		end = end - ini;
		ini = 0;
	}

	bool finished()
	{
		return end==s.length();
	}
};

int main()
{
	long windous;
	cin >> windous;
	string s;
	cin >> s;
	string s2 = s;
	for (int i = 0; i < s.length(); ++i)
	{
		s2[i] = s[s.length()-i-1];
		s2[s.length()-i-1] = s[i];
	}

	long long hashes1[s.length()-windous+1];
	long long hashes2[s.length()-windous+1];
	RollingHash RH1(s,windous);
	hashes1[0] = RH1.getHashValue();
	int agg = 1;
	while(!RH1.finished())hashes1[agg++] = RH1.nextHashValue();

	RollingHash RH2(s2,windous);
	hashes2[s.length()-windous] = RH2.getHashValue();
	agg = s.length()-windous-1;
	while(!RH2.finished())hashes2[agg--] = RH2.nextHashValue();

	long num=0;
	for (int i = 0; i < s.length()-windous+1; ++i)
	{
		if(hashes1[i] == hashes2[i])num++;
	}
	cout << num << endl;
}