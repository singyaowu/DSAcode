//#define Phonebook
#ifdef Phonebook
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define INDEX_TO_CHAR(i) (i + (int)'a')
using namespace std;
struct TriesNode
{
	TriesNode* child[26];
	int count = 0;
};
void insertTrie(TriesNode *triesNode, string charcacter)
{
	int length = charcacter.length();
	int index;
	TriesNode* triesNodeNow = triesNode;
	for (int i = 0; i < length; i++) {
		index = CHAR_TO_INDEX(charcacter[i]);
		if (triesNodeNow->child[index] == NULL) {
			triesNodeNow->child[index] = new TriesNode();
			triesNodeNow = triesNodeNow->child[index];
			triesNodeNow->count++;
			for (int i = 0; i < 26; i++)
			{
				triesNodeNow->child[i] = NULL;
			}
		}
		else {
			triesNodeNow = triesNodeNow->child[index];
			triesNodeNow->count++;
		}
	}
	//triesNodeNow->count++;
}
int searchTree(TriesNode* triesNodeNow, string number) {
	int length = number.length();
	int index;
	for (int i = 0; i < length; i++) {
		index = CHAR_TO_INDEX(number[i]);
		triesNodeNow = triesNodeNow->child[index];
	}
	return triesNodeNow->count;
}
stack<TriesNode*> lastNode;
int findCount(TriesNode* triesNodeNow, string number1, string number2, int cover)
{
	int length = number1.length();
	int index;
	int counting = 0;
	for (int i = 0; i < length; i++) {
		index = CHAR_TO_INDEX(number1[i]);
		lastNode.push(triesNodeNow);
		triesNodeNow = triesNodeNow->child[index];
	}
	counting += triesNodeNow->count;
	int indexnow = length - 2;
	while (!lastNode.empty() && indexnow >= cover) {
			for (int j = CHAR_TO_INDEX(number1[indexnow]) + 1; j < 26; j++) {
				if (lastNode.top()->child[j] != NULL)
					counting += lastNode.top()->child[j]->count;
			}
			lastNode.pop();
			indexnow--;
	}
	triesNodeNow = lastNode.top();
	for (int i = cover; i < length; i++) {
		index = CHAR_TO_INDEX(number2[i]);
		for (int j = 0; j < index; j++) {
			if(triesNodeNow->child[j]!=NULL)
				counting += triesNodeNow->child[j]->count;
		}
		//lastNode.push(triesNodeNow);
		triesNodeNow = triesNodeNow->child[index];
	}
	return counting;
}
int main()
{
	int N;
	TriesNode tries;
	for (int i = 0; i < 26; i++)
	{
		tries.child[i] = NULL;
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int operation;
		cin >> operation;
		switch (operation)
		{
		case 1: {
			string phoneNumber;
			cin >> phoneNumber;
			insertTrie(&tries, phoneNumber);
			break;
		}
		case 2: {
			int total = 0;
			string phrase1, phrase2;
			cin >> phrase1 >> phrase2;
			bool isCover = true;
			int cover = 0;
			for (int j = 0; j < phrase1.size(); j++) {
				if (phrase1[j] != phrase2[j]) {
					cover = j;
					isCover = false;
					break;
				}
			}
			if(isCover){
				int num1 = searchTree(&tries, phrase1);
				int num2 = searchTree(&tries, phrase2);
				total = num1 - num2 + 1;
			}
			else {
				total = findCount(&tries, phrase1, phrase2, cover);
			}
			cout << total<< "\n";
			break;
		}
		}
	}
	return 0;
}
#endif
