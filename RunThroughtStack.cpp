#define stacke
#ifdef stacke
#include <iostream>
#include <stack>

using namespace std;
void sort(stack<int>sortStack, int N,int numNext, int output[], int index)
{
	if (numNext > N) {
		while (!sortStack.empty()) {
			output[index] = sortStack.top();
			sortStack.pop();
			index++;
		}
		for (int i = 0; i < N; i++) {
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}
	sortStack.push(numNext);
	sort(sortStack, N, numNext + 1, output, index);
	sortStack.pop();
	if (!sortStack.empty()) {
		output[index] = sortStack.top();
		sortStack.pop();
		sort(sortStack, N, numNext, output, index + 1);
	}
}
int main()
{
	int N;
	int index = 0;
	stack<int> sortStack;
	cin >> N;
	int* array = new int[N];
	sort(sortStack, N, 1, array, 0);

    return 0;
}
#endif
