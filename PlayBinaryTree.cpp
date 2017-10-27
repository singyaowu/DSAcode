#ifdef PLAYTREE
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
void search(int N, int M, const int tree[], int store[], unsigned long long indexNow, unsigned long long sumNow, int depthNow)
{
	if (depthNow > N) {
		return;
	}
	sumNow += tree[indexNow];
	store[depthNow] = tree[indexNow];
	if (sumNow == M) {
		for (int i = 0; i < depthNow; i++) {
			cout << store[i] << " ";
		}
		cout << store[depthNow];
		cout <<"\n";
	}
	search(N, M, tree, store, 2 * indexNow, sumNow, depthNow + 1);
	search(N, M, tree, store, 2 * indexNow + 1, sumNow, depthNow + 1);
}
int main()
{
	int N, M;
	cin >> N;
	unsigned long long size = (int)(pow(2, N + 1));
	int* tree = new int[size];
	for (int i = 1; i < size; i++) {
		cin >> tree[i];
	}
	cin >> M;
	int store[20];
	search(N, M, tree, store, 1, 0, 0);
	delete[]tree;
	return 0;
}
#endif