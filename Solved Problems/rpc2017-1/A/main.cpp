#include <bits/stdc++.h>


using namespace std;


class Fraction {
    public:
        Fraction() {
            setValue(0, 1);
        }
        Fraction(int numerator, int denominator) {
            setValue(numerator, denominator);
        }
        int getNumerator() {
            return numerator;
        }
        int getDenominator() {
            return denominator;
        }
        void setValue(int numerator, int denominator) {
            // Support negative numbers.
            if (denominator == 0) {
                denominator = 1;
            } else if (denominator < 0) {
                // put - sign to numerator
                numerator = -numerator;
                denominator = -denominator;
            }
            // All fractions have to be simplified. To do that, we need to find the GCD of two numbers and divide.
            int c = gcd(abs(numerator), abs(denominator));

            this->numerator = numerator / c;
            this->denominator = denominator / c;
        }

        Fraction operator+(Fraction b) {
            return addByValue(b.numerator, b.denominator);
        }
        Fraction operator-(Fraction b) {
            return addByValue(-b.numerator, b.denominator);
        }
        Fraction operator*(Fraction b) {
            return Fraction(numerator * b.numerator, denominator * b.denominator);
        }
        Fraction operator/(Fraction b) {
            return Fraction(numerator * b.denominator, denominator * b.numerator);
        }
        string toString() {
            return toString(numerator, denominator);
        }
        string toMixed() {
            if (abs(numerator) >= denominator) {
                // Get out integer part
                int i = numerator / denominator;
                int n = numerator % denominator;
                string s = to_string(i);
                s += " ";
                if (n != 0) {
                    s += toString(abs(n), denominator);
                }
                return s;
            } else if (numerator == 0) {
                return string("0");
            } else {
                return toString();
            }
        }
        void printBoth() {
            cout << toString() << " == " << toMixed() << endl;
        }
        int lcm(int a, int b) {
            return abs(a * b) / gcd(a, b);
        }
        int gcd(int a, int b) {
            int r;
            while (b > 0) {
                r = a % b;
                a = b;
                b = r;
            }
            return a;
        }


    private:
        int numerator;
        int denominator;

        Fraction addByValue(int bn, int bd) {
            int an = this->numerator;
            int ad = this->denominator;

            // Figure out the new denominator and the factors to get there.
            int nd = lcm(ad, bd);
            int ax = nd / ad;
            int bx = nd / bd;

            int nn = (an * ax) + (bn * bx);

            return Fraction(nn, nd);
        }

        string toString(int numerator, int denominator) {
            string s;
            s += to_string(numerator);
            s += "/";
            s += to_string(denominator);
            return s;
        }
};

int w,h,b;
vector<vector<Fraction> > image;

int dirx[9] = {-1, 0,0,1, 0, -1,1,1,-1};
int diry[9] = { 0, 1,0,0,-1, -1,1,-1,1};

Fraction sumAdj(int i,int j)
{
	Fraction sum = Fraction();
	for (int k = 0; k < 9; ++k)
	{
		int x = (j + dirx[k] + w)%w;
		int y = (j + diry[k] + h)%h;
		sum = sum + image[y][x];
	}
	return sum;
}

void blur()
{
	vector<vector<Fraction> > newImage = vector<vector<Fraction> >(h, vector<Fraction>(w,Fraction()));
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			newImage[i][j] = sumAdj(i,j)/Fraction(9,1);
		}
	}
	image = newImage;
}

int main()
{
	cin >> w >> h >> b;
	image = vector<vector<Fraction> >(h, vector<Fraction>(w,Fraction()));
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			int num; cin >> num;
			image[i][j] = Fraction(num,1);
		}
	}

	for (int i = 0; i < b; ++i)
	{
		blur();
	}

	unordered_set<string> set_;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			set_.insert(image[i][j].toString());
			//cout << image[i][j].toString() << " ";

		}
		//cout << endl;
	}

	cout << set_.size() << endl;
	return 0;

}