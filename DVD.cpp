#ifdef DVD
#include <iostream>
#include <algorithm>
using namespace std;
struct timeDVD
{
	int numDVD;
	int minAddition;
	timeDVD(int num, int min)
	{
		numDVD = num;
		minAddition = min;
	}
	timeDVD()
	{
		numDVD = 0;
		minAddition = 0;
	}
	/*timeDVD operator+(int longa)
	{
		
	}*/
};
timeDVD plusa(timeDVD a, int song , int T)
{
	if (song <= T - a.minAddition)
	{
		a.minAddition = song + a.minAddition;
	}
	else if (song > T)
	{
		a.numDVD = 9999;
	}
	else
	{
		a.numDVD += 1;
		a.minAddition = song;
	}
	return a;
}
timeDVD minin(timeDVD a, timeDVD b)
{
	if (a.numDVD < b.numDVD)
	{
		return a;
	}
	else if (a.numDVD > b.numDVD)
	{
		return b;
	}
	else
	{
		if (a.minAddition > b.minAddition)
			return b;
		else
			return a;
	}
}
timeDVD g[1001][1001];
int main()
{
	int X, N, M, T;
	//X: the number of test data(1 <= X <= 5)
	//N : the number of the songs(1 <= N <= 1, 000)
	//M : the number of disks(1 <= M <= 1, 000)
	//T : the number of the maximum capacity of each disk(1 <= T <= 50)
	cin >> X;
	for (int testIndex = 0; testIndex < X; ++testIndex) 
	{
		cin >> N >> M >> T;
		int songTime[1000];
		for (int j = 0; j < N; ++j) {
			int temp;
			cin >> temp;
			if (temp > T)
				temp = 99999;
			songTime[j] = temp;
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (j == i) 
				{
					g[i][j] = plusa(g[i - 1][j - 1], songTime[i - 1], T);
				}
				else
				{
					//int time = min(g[i - 1][j].numDVD*T + g[i - 1][j].minAddition,
					//	g[i - 1][j - 1].numDVD*T + g[i - 1][j - 1].minAddition + songTime[i]);
					//g[i][j].numDVD = time / T;
					//g[i][j].minAddition = time % T;
					g[i][j] = minin(g[i - 1][j], plusa(g[i - 1][j - 1], songTime[i - 1], T));
				}				
			}
		}
		int maxk = 0;
		for (int k = 1; k <= N; k++)
		{
			if (g[N][k].numDVD < M)
			{
					maxk = k;
			}
		}
		cout << maxk << "\n";
	}
	return 0;
}
#endif
