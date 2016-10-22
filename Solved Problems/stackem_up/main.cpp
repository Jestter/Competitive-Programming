//UVA 10205
#include <bits/stdc++.h>

using namespace std;

string value(int a)
{
	int b = a%13;

	string s = "";

	switch(b)
	{
		case 12:
			s = "Ace"; break;
		case 9:
			s = "Jack"; break;
		case 10:
			s = "Queen"; break;
		case 11:
			s = "King"; break;
		default:
			s = to_string(b+2);
	}	
	return s;
}

string suit(int a)
{
	int b = a/13;
	switch(b)
	{
		case 0: return "Clubs";
		case 1: return "Diamonds";
		case 2: return "Hearts";
		case 3: return "Spades";
		default: break;
	}
	return "none";
}


int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int nshuffles;
		scanf("%d",&nshuffles);
		int shuffles[nshuffles][52];
		
		for (int i = 0; i < nshuffles; ++i)
		{
			for (int j = 0; j < 52; ++j)
			{
				int a;
				scanf("%d",&a);
				shuffles[i][a-1] = j;
			}
		}
		int deck[2][52];
		for (int i = 0; i < 52; ++i)
		{
			deck[0][i] = i;
			deck[1][i] = i;
		}



		int usin = 0;
		char sh;
		scanf("%c",&sh);
		while(scanf("%c",&sh) != EOF)
		{
			//cout << ((int)sh) << endl;
			if(sh == '\n')break;
			int num = 0;
			while(sh != '\n')
			{
				num*=10;
				num+=((int)sh-'0');
				if(scanf("%c",&sh)== EOF)break;
			}
			//cout << num << endl;

			int usin2 = (usin+1)%2;
			for (int i = 0; i < 52; ++i)
			{
				deck[usin2][shuffles[num-1][i]] = deck[usin][i];

				//cout << "deck["<<(shuffles[((int)sh-'0')-1][i])<< "] = " << deck[usin][i] << endl;
			}

			usin = usin2; 
		}

		for (int i = 0; i < 52; ++i)
		{
			cout << value(deck[usin][i]) << " of " << suit(deck[usin][i]) << endl;
		}
		if(tc!=0)cout << endl;
	}
} 