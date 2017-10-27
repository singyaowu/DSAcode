//#define Chords
#ifdef Chords
#include <iostream>
using namespace std;
int C[5001][5001];
int chord[5000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 5001; i++) {
		for (int j = 0; j < 5001; j++) {
			C[i][j] = -1;
		}
	}
	int tmpB, tmpE;
	cin >> tmpB >> tmpE;
	chord[tmpB] = tmpE;
	chord[tmpE] = tmpB;
	while (true)
	{
		cin >> tmpB;
		if (tmpB == 0)
			break;
		cin >> tmpE;
		chord[tmpB] = tmpE;
		chord[tmpE] = tmpB;
	}
	for (int j = 0; j < n; j++) {
		for (int i = j; i >= 0; i--) {
			if (i == j) {
				C[i][j] = 0;
			}
			else {
				int k = chord[j];
				C[i][j] = C[i][j - 1];
				if (i == k) {
					int temp;
					temp = C[i + 1][j - 1] + 1;
					if (C[i][j] < temp)
						C[i][j] = temp;
				}
				else if (k < j && k > i) {
					int temp;
					temp = C[i][k - 1] + C[k + 1][j - 1] + 1;
					if (C[i][j] < temp)
						C[i][j] = temp;
				}
				//else {
				//	C[i][j] = C[i][j - 1];
				//}
			}
		}
	}
	cout << C[0][n - 1] << '\n';
	return 0;
}
#endif#define Chords
#ifdef Chords
#include <iostream>
using namespace std;
int C[5001][5001];
int chord[5000];
int main()
{
	int n;
	cin >> n;
	//int C[n][n];
	//int chord[n];

	int tmpB, tmpE;
	cin >> tmpB >> tmpE;
	chord[tmpB] = tmpE;
	chord[tmpE] = tmpB;
	while(true)
	{	
		cin >> tmpB;
		if (tmpB == 0)
			break;
		cin >> tmpE;
		chord[tmpB] = tmpE;
		chord[tmpE] = tmpB;
	}
	for (int j = 0; j < n; j++){
		for (int i = j; i >= 0; i--) {
			if (i == j) {
				C[i][j] = 0;
			}
			else {
				int k = chord[j];
				C[i][j] = C[i][j - 1];
				if (i == k) {
					int temp;
					temp = C[i + 1][j - 1] + 1;
					if (C[i][j] < temp)
						C[i][j] = temp;
				}
				else if (k < j && k > i) {
					int temp;
					temp = C[i][k - 1] + C[k + 1][j - 1] + 1;
					if (C[i][j] < temp)
						C[i][j] = temp;
				}
				//else {
				//	C[i][j] = C[i][j - 1];
				//}
			}
		}
	}
	cout << C[0][n - 1] << '\n';
	return 0;
}
#endif