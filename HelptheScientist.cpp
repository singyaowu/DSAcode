//#define help
#ifdef help
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;
string answerString = "";
string valueA[200000];
long long  int child[200000];
long long int index;
struct Node
{
	string value;
	long long int size = 0;
	Node* children = NULL;
};
void buildTree(Node &nodeNow)
{
	nodeNow.value = valueA[index];
	if (child[index] > 0) {
		nodeNow.size = child[index];
		nodeNow.children = new Node[child[index]];
		for (int i = 0; i < nodeNow.size; i++)
		{
			index++;
			buildTree(nodeNow.children[i]);
		}
	}
}
void postOrder(const Node &nodeNow)
{
	for (int i = 0; i < nodeNow.size; i++)
	{
		postOrder(nodeNow.children[i]);
	}
	answerString += (nodeNow.value + " ");
}
void deleteTree(Node &nodeNow)
{
	for (int i = 0; i < nodeNow.size; i++)
	{
		deleteTree(nodeNow.children[i]);
	}
	if (nodeNow.children != NULL)
	{
		delete[]nodeNow.children;
	}
}
void levelOrder(queue<Node> &answerq)
{
	while (!answerq.empty())
	{
		answerString += (answerq.front().value + " ");
		for (int i = 0; i < answerq.front().size; i++)
		{
			answerq.push(answerq.front().children[i]);
		}
		answerq.pop();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, n;
	cin >> T >> n;
	for (int i = 0; i < 200000; i++)
	{
		valueA[i] = "";
		
	}
	for (int i = 0; i < 200000; i++)
	{
		child[i] = 0;
	}
	for (int i = 0; i < T; i++)
	{
		int indexValue = 0;
		int indexChild = 0;
		for (int j = 0; j < n; j++)
		{
			//valueA[indexValue] = "";
			long long temp;
			char tempc[15];
			cin >> temp;
			sprintf(tempc, "%d", temp);
			valueA[indexValue] = tempc;
			indexValue++;
		}
		for (int j = 0; j < n; j++)
		{
			cin >> child[indexChild];
			indexChild++;
		}
		Node root;
		index = 0;
		answerString = "";
		buildTree(root);
		postOrder(root);
		for (int j = 0; j < answerString.size() - 1; j++)
		{
			cout << answerString[j];
		}
		cout << '\n';
		answerString = "";
		queue<Node> levelQueue;
		levelQueue.push(root);
		levelOrder(levelQueue);
		for (int j = 0; j < answerString.size() - 1; j++)
		{
			cout << answerString[j];
		}
		cout << '\n';
		deleteTree(root);
	}
	return 0;
}
#endif