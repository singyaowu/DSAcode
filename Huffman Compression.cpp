//#define Huffman
#ifdef Huffman
#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct Node
{
	string path = "";
	int count = 0;
};

int main()
{
	string password[128];
	for (int i = 0; i < 128; i++)
	{
		password[i] = "";
	}
	char treeKey;
	cin >> treeKey;
	stack<Node> tree;
	while (treeKey != 'E')
	{
		switch (treeKey)
		{
		case 'I':
		{			
			if (!tree.empty()){
				tree.top().count += 1;
				Node temp;
				if (tree.top().count == 2){
					temp.path = tree.top().path + "1";
					tree.pop();
					tree.push(temp);
				}
				else{
					temp.path += tree.top().path + "0";
					tree.push(temp);
				}
			}
			else{
				Node temp;
				tree.push(temp);
			}
			break;
		}
		case 'L':
		{
			char tempC;
			cin >> tempC;
			tree.top().count++;
			if (tree.top().count == 1) {
				password[tempC] = tree.top().path + "0";
			}
			else
			{
				password[tempC] = tree.top().path + "1";
				tree.pop();
			}

			break;
		}
		}
		cin >> treeKey;
	}
	int operation;
	cin >> operation;
	switch (operation)
	{
	case 0:
	{
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			char c;
			cin >> c;
			cout << password[c] << "\n";

		}
		break;
	}
	case 1:
	{
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			string c;
			cin >> c;
			for (int i = 0; i < 128; i++) {
				if (password[i] == c)
				{
					char c = i;
					cout << c << "\n";
				}
			}
		}
		break;
	}
	}
	return 0;
}
#endif