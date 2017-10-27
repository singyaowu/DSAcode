#ifdef KABAN
#include <iostream>
using namespace std;
int stair[101][10001];
int main()
{
	int t, n, m, max;
	int ci[102];
	int di[2002];
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m >> max;
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k <= max; k++)
				stair[j][k] = 0;
		}
		for (int j = 0; j < n; j++)
		{
			cin >> ci[j];
		}
		for (int j = 0; j < m; j++)
		{
			cin >> di[j];
			for (int k = 0; k < n + 1; k++)
			{
				stair[k][di[j]] = -1;
			}			
		}
		stair[0][0] = 1;
		for (int  j = 1; j < n + 1; j++)
		{
			for (int k = 0; k < max + 1; k++)
			{
				if (stair[j - 1][k] == 1) {
					if ((k + ci[j - 1] <= max) && stair[j][k + ci[j - 1]] != -1)
						stair[j][k + ci[j - 1]] = 1;
					if(((k - ci[j - 1] >= 0) && stair[j][k - ci[j - 1]] != -1))
						stair[j][k - ci[j - 1]] = 1;
				}
			}
		}
		for (int j = max; j >= 0; --j)
		{
			if (stair[n][j] == 1) {
				cout << j << "\n";
				break;
			}
			if (j == 0) {
				cout << "-1\n";
			}
		}
	}
	
	return 0;
}
#endif