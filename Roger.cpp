//#define Roger
#ifdef Roger
#include <iostream>
#include <stack>
using namespace std;
int order[100002];
int arraystacl[100002];
int N;
bool isY1 = false;
//void sort(stack<int>sortStack, int numNext, int index)
//{
//	if (isY1)return;
//	else {
//		if (numNext > N) {
//			while (!sortStack.empty()) {
//				arraystacl[index] = sortStack.top();
//				sortStack.pop();
//				index++;
//			}
//			for (int i = 0; i < N; i++) {
//				if (arraystacl[i] == order[i]) {
//					if (i == N - 1)
//						isY1 = true;
//				}
//				else {
//					break;
//				}
//			}
//			return;
//		}
//		sortStack.push(numNext);
//		sort(sortStack, numNext + 1, index);
//		sortStack.pop();
//		if (!sortStack.empty()) {
//			arraystacl[index] = sortStack.top();
//			sortStack.pop();
//			sort(sortStack, numNext, index + 1);
//		}
//	}
//}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		isY1 = true;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> order[j];
		}
		stack<int> sortStack;
		int hasEnter = 0;
		for (int k = 1; k < order[0]; k++) {
			sortStack.push(k);
		}
		hasEnter = order[0];
		for (int j = 1; j < N; j++) {			
			if (order[j] > hasEnter) {
				for (int k = hasEnter + 1; k < order[j]; k++) {
					sortStack.push(k);
				}
				hasEnter = order[j];
			}
			else if (order[j] < order[j - 1]) {
				if (sortStack.empty() || order[j] != sortStack.top()) {
					isY1 = false;
					break;
				}
				else {
					sortStack.pop();
				}
			}
			else {
				isY1 = false;
				break;
			}
		}		
		//sort(sortStack, 1, 0);
		if (isY1) {
			cout << "Y 1\n";
		}
		else {
			cout << "Y 2\n";
		}
	}
	return 0;
}
#endif