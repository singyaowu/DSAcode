//#define Water
#ifdef Water
#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;
void clear(stack<int> &landPart)
{
	while (!landPart.empty())
	{
		landPart.pop();
	}
}
int main()
{
	stack<int> landPart;
	//vector<int> land;
	int waterTotal = 0;
	int leftBound;
	int temp;
	while (scanf("%d", &temp) != EOF)
	{
		if (temp == 0)
		{
			clear(landPart);
			leftBound = 0;
		}
		else//現在不是水
		{
			if (landPart.empty())
			{
				landPart.push(temp);
				leftBound = temp;
			}
			else
			{
				if (temp < leftBound) {
					if (temp <= landPart.top()){
						landPart.push(temp);
					}
					else{
						int count = 0;
						while (temp > landPart.top())
						{
							waterTotal += temp - landPart.top();
							count++;
							landPart.pop();
						}
						for (int i = 0; i < count; i++)
						{
							landPart.push(temp);
						}
						landPart.push(temp);
					}
				}
				else{//temp >= leftBound
					while (!landPart.empty())
					{
						waterTotal += leftBound - landPart.top();
						landPart.pop();
					}
					leftBound = temp;
					landPart.push(temp);
				}
			}
		}
	}
	cout << waterTotal;
	return 0;
}
#endif