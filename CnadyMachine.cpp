#ifdef CandyMachine
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int treeHeap[5000001];
void rearrange(priority_queue<int, vector<int>, greater<int> >&space)
{
	int i = 1;
	bool isWhileHappened = false;
	while((treeHeap[2 * i] != 0 || treeHeap[2 * i + 1] != 0))
	{
		if ((treeHeap[2 * i] >= treeHeap[2 * i + 1]))
		{
			treeHeap[i] = treeHeap[2 * i];
			treeHeap[2 * i] = 0;
			i = 2 * i;
		}
		else
		{
			treeHeap[i] = treeHeap[2 * i + 1];
			treeHeap[2 * i + 1] = 0;
			i = 2 * i + 1;
		}
		isWhileHappened = true;
	}
	if (!isWhileHappened )
	{
		treeHeap[i] = 0;
	}
	space.push(i);
}
int main()
{
	priority_queue<int, vector<int>, greater<int> > space;
	int instruction;
	int index = 1;
	while (scanf("%d", &instruction) != EOF)
	{
		switch (instruction)
		{
		case 1:
		{
			int weight;
			scanf("%d", &weight);		
			/*while (true)
			{
				if (treeHeap[index] == 0) {
					treeHeap[index] = weight;
					break;
				}
				
			}*/
			if (!space.empty())
			{
				treeHeap[space.top()] = weight;
				space.pop();
			}
			else
			{
				treeHeap[index] = weight;
				index++;
			}
			
			break;
		}
		case 2:
		{
			printf("%d\n", treeHeap[1]);
			//cout << treeHeap[1] << "\n";
			if (treeHeap[1] != 0)
				rearrange(space);
			break;
		}
		}
	}
	return 0;
}
#endif