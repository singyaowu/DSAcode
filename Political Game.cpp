//#define Politic
#ifdef Politic
#include <iostream>
#include<vector>
using namespace std;
struct Jyou
{
	int X1, X2, Y1, Y2, Z1, Z2;
};
int main()
{
	vector<Jyou> jyou;
	int S, P;
	cin >> S >> P;
	int numYeYuen = 0;
	int numPro = 0;
	for (int i = 0; i < S; i++)
	{
		Jyou tmp;
		cin >> tmp.X1 >> tmp.X2 >> tmp.Y1 >> tmp.Y2 >> tmp.Z1 >> tmp.Z2;
		jyou.push_back(tmp);
		numYeYuen += tmp.X1 + tmp.X2;
		numPro += tmp.X1;
	}


	return 0;
}
#endif