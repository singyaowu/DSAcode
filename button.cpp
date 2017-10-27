//#define btn
#ifdef btn
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int Left[500000];
int Right[500000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N, Q;
		cin >> N >> Q;
		for (int j = 0; j < N; j++)
		{
			cin >> Left[j];
			cin >> Right[j];
		}
		sort(Left, Left + N);
		sort(Right, Right + N);
		for (int j = 0; j < Q; j++)
		{
			int query;
			int timesTurn = 0;
			cin >> query;
			int head = 0;
			int last = N - 1;
			int mid = N / 2;
			bool isFound = false;
			while (last >= head)
			{
				mid = head + (last - head) / 2;
				if (query > Left[mid]) {
					head = mid + 1;
				}
				else if (query < Left[mid]) {
					last = mid - 1;
				}
				else {//query == Left[mid]
					isFound = true;
					break;
				}
			}
			if (isFound) {
				while (mid + 1 < N && Left[mid + 1] == query)
				{
					++mid;
				}
				timesTurn = mid + 1;
			}
			else {
				if (query > Left[N - 1]) {
					timesTurn += N;
				}
				else if (query < Left[0]) {
					timesTurn += 0;
				}
				else if (Left[mid] < query) {//陣列值現在比query值小，找離query最近的左端點
					while (Left[mid + 1] < query) {
						++mid;
					}
					timesTurn += mid + 1;
				}
				else if (Left[mid] > query) {//陣列值現在比query大，找離query最近的左端點
					while (Left[mid] > query) {
						--mid;
					}
					timesTurn += mid + 1;
				}
				else {
					timesTurn += mid + 1;
				}
			}
			head = 0; last = N - 1; mid = N / 2; isFound = false;
			while (last >= head)
			{
				mid = head + (last - head) / 2;
				if (query > Right[mid]) {
					head = mid + 1;
				}
				else if (query < Right[mid]) {
					last = mid - 1;
				}
				else {//query == Left[mid]
					isFound = true;
					break;
				}
			}
			if (isFound) {
				while (mid - 1 >= 0 && Right[mid - 1] == query)
				{
					--mid;
				}
				timesTurn += mid;
			}
			else {
				if (query > Right[N - 1]) {
					timesTurn += N;
				}
				else if (query < Right[0]) {
					timesTurn += 0;
				}
				else if (Right[mid] < query) {//陣列值現在比query值小，找離query最近的右端點
					while (Right[mid] < query) {
						++mid;
					}
					timesTurn += mid;
				}
				else if (Right[mid] > query) {//陣列值現在比query大，找離query最近的右端點
					while (Right[mid - 1] > query) {
						--mid;
					}
					timesTurn += mid;
				}
				else {
					timesTurn += mid + 1;
				}
			}
			if(timesTurn % 2 == 0) {
				cout << "0\n";
			}
			else {
				cout << "1\n";
			}
		}
	}
	return 0;
}
#endif