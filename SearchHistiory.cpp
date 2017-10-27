#ifdef SearchHis
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define INDEX_TO_CHAR(i) (i + (int)'a')
using namespace std;

struct TriesNode
{
	TriesNode* child[26];
	bool isWord;
};
void searchR(TriesNode *triesNodeNow, string wordnow);
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
			for (int i = 0; i < 26; i++)
			{
				triesNodeNow->child[i] = NULL;
			}
		}
		else
			triesNodeNow = triesNodeNow->child[index];
	}
	triesNodeNow->isWord = true;
}
void searchTree(TriesNode *N, string word)
{
	int length = word.length();
	int index;

	TriesNode* triesNodeNow = N;
	for (int i = 0; i < length; i++) {
		index = CHAR_TO_INDEX(word[i]);
		if (triesNodeNow->child[index] != NULL) {
			triesNodeNow = triesNodeNow->child[index];
		}
		else {
			cout << "NO MATCHING!\n";
			return;
		}		
	}
	searchR(triesNodeNow, word);
}
void searchR(TriesNode *triesNodeNow, string wordnow)
{
	if (triesNodeNow->isWord)
	{
		cout << wordnow << "\n";
	}
	for (int i = 0; i < 26; i++)
	{
		if (triesNodeNow->child[i] != NULL)
		{
			searchR(triesNodeNow->child[i], wordnow + (char)(INDEX_TO_CHAR(i)));
		}
	}
	

}
int main()
{
	int N, M;
	TriesNode tries;
	cin >> N;
	string data;
	for (int i = 0; i < 26; i++)
	{
		tries.child[i] = NULL;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		insertTrie(&tries, data);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> data;
		searchTree(&tries, data);
	}
	return 0;
}
#endif