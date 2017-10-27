//#define Ming 1
#ifdef Ming
#include <iostream>
#include <algorithm>
using namespace std;
struct Candy 
{
	int point;
	int number;
	int dollar;
};
int pointMax[150000];
int main()
{
	int N, M;
	Candy candy[400];
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> candy[i].number >> candy[i].dollar >> candy[i].point;
	}
	for(int i = 0; i < N; i++)
	{		
		int numAvailable = M / candy[i].dollar > candy[i].number ? candy[i].number : M / candy[i].dollar;
		for (int j = 1; numAvailable > 0; j *= 2)
		{
			if (j > numAvailable)
				j = numAvailable;
			numAvailable -= j;
			for (int k = M; k >= candy[i].dollar * j; --k)
			{
				pointMax[k] = max(pointMax[k], pointMax[k - candy[i].dollar * j] + candy[i].point * j);
			}
		}
	}
	cout << pointMax[M];
	return 0;
}
#endif