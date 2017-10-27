//#define Han
#ifdef Han
#include <iostream>
//int boxes[10000];
//int boxesSum[10000];
//int dpBox[10000][10000];
using namespace std;
int sum(int boxes[], int boxesSum[], int a, int b)
{
	return(boxesSum[b] - boxesSum[a] + boxes[a]);
}
int max(int a, int b)
{
	return (a > b ? a : b);
}
int main()
{
	int N;
	cin >> N;
	int dpBox[N][N];
	int boxes[N];
	int boxesSum[N];
	cin >> boxes[0];
	boxesSum[0] = boxes[0];
	for (int i = 1; i < N; i++)
	{
		cin >> boxes[i];
		boxesSum[i] = boxesSum[i - 1] + boxes[i];
	}
	for (int j = 0; j < N; j++) {
		for (int i = j; i >= 0; i--)
		{
			if (i == j) {
				dpBox[i][j] = boxes[i];
			}
			else {
				dpBox[i][j] = max((sum(boxes, boxesSum, i + 1, j) - dpBox[i + 1][j] + boxes[i]),
					(sum(boxes, boxesSum, i, j - 1) - dpBox[i][j - 1] + boxes[j]));
			}
		}		
	}
	int hougonJenChengon = boxesSum[N - 1] - 2 * dpBox[0][N - 1];
	if (hougonJenChengon > 0) {
		cout << "N\n" << hougonJenChengon;
	}
	else {
		cout << "Y\n" << -hougonJenChengon;
	}
	return 0;
}
#endif