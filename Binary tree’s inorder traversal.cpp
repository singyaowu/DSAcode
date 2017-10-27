#ifdef BinTreeTraversal
#include <iostream>
#include <vector>
using namespace std;
void inorder(vector<int> &tree, int node)
{
	if (tree[node] == -1)
		return;
	if (2 * node <= (int)tree.size() - 1)
	{
		inorder(tree, 2 * node);
	}
	cout << tree[node] << " ";
	if (2 * node + 1 <= (int)tree.size() - 1)
	{
		inorder(tree, 2 * node + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> tree;
		tree.push_back(-1);
		int lastIndex;
		cin >> lastIndex;
		for (int j = 1; j <= lastIndex; j++)
		{
			int temp;
			cin >> temp;
			tree.push_back(temp);
		}
		inorder(tree, 1);
		if (i != n - 1)
			cout << '\n';
	}
	return 0;
}
#endif