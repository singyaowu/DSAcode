#ifdef department
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct IDwithParentNode
{
	int id;
	int idParent;
	vector<IDwithParentNode*> childs;
	IDwithParentNode* parent;
};
void preOrder(priority_queue<int,vector<int>,greater<int> > &killList, IDwithParentNode ID)
{
	killList.push(ID.id);
	int sizeChild =ID.childs.size();
	for (int i = 0; i < sizeChild; i++)
	{
		preOrder(killList, *(ID.childs[i]));
	}
}
int main()
{
	int n;
	cin >> n;
	IDwithParentNode* ID = new IDwithParentNode[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ID[i].id;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> ID[i].idParent;
		for (int j = 0; j < n; j++)
		{
			if (ID[j].id == ID[i].idParent) {
				ID[j].childs.push_back(&ID[i]);
				ID[i].parent = &ID[j];
				break;
			}
		}
	}
	int idKilled;
	cin >> idKilled;
	for (int i = 0; i < n; i++)
	{
		if (ID[i].id == idKilled) {
			priority_queue<int,vector<int>,greater<int> > killList;
			preOrder(killList, ID[i]);
			while (!killList.empty())
			{
				if(killList.size() == 1)
					cout << killList.top();
				else 
					cout << killList.top() << " ";
				killList.pop();
			}
			break;
		}
	}
	return 0;
}
#endif
