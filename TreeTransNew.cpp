//#define Transforma
#ifdef Transforma
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#define MAX 16777216

using namespace std;
int binaryTree[MAX];
void preOrder(int index, int size)
{
	//cout << binaryTree[index] << " ";
	//int k = 2 * index;
	//while (k <= size && binaryTree[k] != -1)
	//{
	//	preOrder(k, size);
	//	k = 2 * k + 1;
	//}
	if (binaryTree[index] == -1)
		return;
	cout << binaryTree[index] << " ";
	if (2 * index <= size)
	{
		preOrder(2 * index, size);
	}
	if (2 * index + 1 <= size)
	{
		preOrder(2 * index + 1, size);
	}
}
void postOrder(int index, int size)
{
	//int k = 2 * index;
	//while (k <= size && binaryTree[k] != -1)
	//{
	//	postOrder(k, size);
	//	k = 2 * k + 1;
	//}
	//cout << ' ' << binaryTree[index];
	if (binaryTree[index] == -1)
		return;
	if (2 * index <= size)
	{
		postOrder(2 * index, size);
	}
	cout << " " << binaryTree[index];
	if (2 * index + 1 <= size)
	{
		postOrder(2 * index + 1, size);
	}
}

void levelOrder(queue<int> &inorderQueue, int size)
{
	cout << binaryTree[inorderQueue.front()] << " ";
	int index = inorderQueue.front();
	int k = 2 * index;
	while (k <= size && binaryTree[k] != -1)
	{
		inorderQueue.push(k);
		k = 2 * k + 1;
	}
	inorderQueue.pop();
	if (!inorderQueue.empty())
		levelOrder(inorderQueue, size);
}
int main()
{
	int H;
	cin >> H;
	while (H != 0)
	{
		binaryTree[0] = -1;
		int size = (int)(exp2(H) - 1);

		for (int i = 1; i <= size; i++)
		{
			int temp;
			cin >> temp;
			binaryTree[i]  = temp;
		}
		queue<int> levelorderQueue;
		levelorderQueue.push(1);
		cout << "preorder: ";
		preOrder(1, size);
		cout << "\n";
		cout << "postorder:";
		postOrder(1, size);
		cout << "\n";
		cout << "level order: ";
		levelOrder(levelorderQueue, size);
		cout << "\n\n";

		cin >> H;
	}
	return 0;
}
#endif