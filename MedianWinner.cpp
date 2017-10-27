#ifdef Winner
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
void Extract_Median(priority_queue<int> &first, priority_queue<int, vector<int>, greater<int> >&second)
{		
	if (first.size() == second.size() + 1)
	{	
		printf("Player ID:%d is out!\n", first.top());
		first.pop();
		return;
	}
	printf("Player ID:%d is out!\n", first.top());
	first.pop();
	first.push(second.top());
	second.pop();
	return;
}

int Find_Median(priority_queue<int> &first, priority_queue<int, vector<int>, greater<int> >&second)
{
	if (first.size() == second.size() + 1)
	{
		return first.top();
	}
	int temp = (first.top() + second.top()) / 2;
	return temp;
}
void Insert(priority_queue<int> &first, priority_queue<int, vector<int>, greater<int> >&second, int ID)
{
	if (first.size() == second.size() + 1)
	{
		if (ID < first.top()) 
		{
			second.push(first.top());
			first.pop();
			first.push(ID);
			return;
		}
		second.push(ID);
	}
	else if (first.size() == second.size())
	{
		if (first.size() == 0)
		{
			first.push(ID);
			return;
		}
		if (ID > second.top())
		{
			first.push(second.top());
			second.pop();
			second.push(ID);
			return;
		}
		first.push(ID);
	}	
}
int main()
{
	int N, operation;
	priority_queue<int> first;
	priority_queue<int, vector<int>, greater<int> >second;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> operation;
		switch (operation)
		{
		case 1:
			int ID;	
			cin >> ID;
			Insert(first, second, ID);
			break;
		case 2:			
			printf("Current median ID:%d\n", Find_Median(first, second));
			break;
		case 3:
			Extract_Median(first, second);
			break;
		}
	}
	printf("The winner ID: %d!!!\n", first.top());
	return 0;
}
#endif