#ifdef CoutBool
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int T[2000][2000];
int F[2000][2000];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int w;
		cin >> w;
		vector<int> oper;
		vector<bool> boolean;

		string temp;
		int symbolCount = 0;
		for (int j = 0; j < w; j++)
		{
			cin >> temp;
			if (temp == "true")
			{
				boolean.push_back(true);
				symbolCount++;
			}
			else if (temp == "false")
			{
				boolean.push_back(false);
				symbolCount++;
			}
			else if (temp == "and")
			{
				oper.push_back(1);
			}
			else if (temp == "or")
				oper.push_back(2);
			else if (temp == "xor")
				oper.push_back(3);
		}
		for (int i = 0; i < symbolCount; i++)
		{
			if (boolean[i]){
				T[i][i] = 1;
				F[i][i] = 0;
			}
			else{
				T[i][i] = 0;
				F[i][i] = 1;
			}
		}
		for (int interval = 1; interval < symbolCount; ++interval)
		{
			for (int i = 0, j = i + interval; j < symbolCount; ++j, ++i) {
				T[i][j] = 0;
				F[i][j] = 0;
				for (int k = i; k < j; ++k)
				{					
					switch (oper[k])
					{
					case 1:
						T[i][j] += T[i][k] * T[k + 1][j];
						F[i][j] += (T[i][k] + F[i][k])*(T[k + 1][j] + F[k + 1][j]) - T[i][k] * T[k + 1][j];
						break;
					case 2:
						F[i][j] += F[i][k] * F[k + 1][j];
						T[i][j] += (T[i][k] + F[i][k])*(T[k + 1][j] + F[k + 1][j]) - F[i][k] * F[k + 1][j];
						break;
					case 3:
						T[i][j] += T[i][k] * F[k + 1][j] + F[i][k] * T[k + 1][j];
						F[i][j] += T[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j];
						break;
					}

				}
			}
		}
		cout << T[0][symbolCount - 1] << "\n";
	}
	return 0;
}
#endif