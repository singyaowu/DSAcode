#ifdef PLZ
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcsArray[100000][27];
int main()
{
	int n;
	cin >> n;
	string standard = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 10000; i++)
		lcsArray[0][i] = 0;
	for (int i = 0; i < 27; i++)
		lcsArray[i][0] = 0;
	for (int i = 0; i < n; i++)
	{
		string query;
		cin >> query;
		int lengthQuery = query.length() + 1;
		for (int j = 1; j < lengthQuery; j++) 
		{
			for (int k = 1; k < 27; k++)
			{
				if (query[j - 1] == standard[k - 1])
					lcsArray[j][k] = lcsArray[j - 1][k - 1] + 1;
				else {
					lcsArray[j][k] = max(lcsArray[j][k-1], lcsArray[j-1][k]);
				}
			}
		}
		cout << lcsArray[lengthQuery - 1][26] << "\n";
	}
	return 0;
}
#endif