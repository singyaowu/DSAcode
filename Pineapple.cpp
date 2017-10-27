#ifdef pineapple
#include <iostream>
#include <string>
using namespace std;
int matrix[1000][1000];
void counting(int N, int &count)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((matrix[i][j] == 1) && (matrix[i][j + 1] == 1) && (matrix[i + 1][j] == 1) && (matrix[i + 1][j + 1] == 1)) {
				count++;
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}
	if(N > 1)
		counting(N - 1, count);
}
int main()
{
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string line;
		int count = 0;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> line;
			for (int k = 0; k < N; k++)
			{
				if (line[k] == '1') {
					matrix[j][k] = 1;
					count++;
				}
				else
					matrix[j][k] = 0;
			}
			cin.ignore();
		}
		counting(N - 1, count);
		cout << count << endl;
	}
	return 0;
}
#endif