#ifdef encodedSystem
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool nextPermutation(char P[], int size)
{
	for (int i = size - 1; i > 0; i--) {
		if (P[i - 1] < P[i]) {
			int j = size - 1;
			while (P[j] <= P[i - 1]) {
				j--;
			}
			char temp;
			temp = P[i - 1];
			P[i - 1] = P[j];
			P[j] = temp;
			reverse(P + i, P + size);
			return true;
		}
	}
	return false;
}

int main()
{
	int N, D;
	int size;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		char P[10];
		cin >> P;
		size = strlen(P);
		bool flag = true;
		for (int j = 0; j < D; j++) {
			if (!nextPermutation(P, size)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << P << endl;
		}
		else {
			cout << "NOPE!!\n";
		}
	}
	return 0;
}
#endif