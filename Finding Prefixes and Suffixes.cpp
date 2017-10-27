//#define Prefix
#ifdef Prefix
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define INDEX_TO_CHAR(i) (i + (int)'a')
using namespace std;
int T;
vector<string> prefixes;
vector<string>words;
struct TriesNode
{
	TriesNode* child[26];
	int count = 0;
};
//void searchR(TriesNode *triesNodeNow, string wordnow);
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
	triesNodeNow->count++;
}
void insertReverseTrie(TriesNode *triesNode, string charcacter)
{
	int length = charcacter.length();
	int index;
	TriesNode* triesNodeNow = triesNode;
	for (int i = length - 1; i >= 0; i--) {
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
	triesNodeNow->count++;
}
bool findPrefix(TriesNode *triesNode, string prefix, int &wordbelow)
{
	bool isPrefix = false;
	int wordnum = 0;
	for (int i = 0; i < 26; i++) {
		if (triesNode->child[i] != NULL) {
			if (findPrefix(triesNode->child[i], (prefix + char(i + 'a')),wordnum)) {
				isPrefix = true;
			}
			delete triesNode->child[i];
		}
	}
	if (!isPrefix) {
		//for (int i = 0; i < 26; i++) {
		//	if (triesNode->child[i] != NULL)
		//	{
		//		times++;
		//	}
		//}
		wordnum += triesNode->count;
		wordbelow += wordnum;
		if (wordnum >= T) {
			prefixes.push_back(prefix);
			return true;
		}
		return false;
	}
	else {
		return true;
	}
}
bool findsuffix(TriesNode *triesNode, string suffix, int &wordbelow)
{
	bool isPrefix = false;
	int wordnum = 0;
	for (int i = 0; i < 26; i++) {
		if (triesNode->child[i] != NULL) {
			if (findsuffix(triesNode->child[i], (char(i + 'a') + suffix), wordnum)) {
				isPrefix = true;
			}
			delete triesNode->child[i];
		}
	}
	if (!isPrefix) {
		wordnum += triesNode->count;
		wordbelow += wordnum;
		if (wordnum >= T) {
			prefixes.push_back(suffix);
			return true;
		}
		return false;
	}
	else {
		return true;
	}
}
//void searchTree(TriesNode *N, string word)
//{
//	int length = word.length();
//	int index;
//
//	TriesNode* triesNodeNow = N;
//	for (int i = 0; i < length; i++) {
//		index = CHAR_TO_INDEX(word[i]);
//		if (triesNodeNow->child[index] != NULL) {
//			triesNodeNow = triesNodeNow->child[index];
//		}
//		else {
//			cout << "NO MATCHING!\n";
//			return;
//		}
//	}
//	searchR(triesNodeNow, word);
//}
//void searchR(TriesNode *triesNodeNow, string wordnow)
//{
//	if (triesNodeNow->isWord)
//	{
//		cout << wordnow << "\n";
//	}
//	for (int i = 0; i < 26; i++)
//	{
//		if (triesNodeNow->child[i] != NULL)
//		{
//			searchR(triesNodeNow->child[i], wordnow + (char)(INDEX_TO_CHAR(i)));
//		}
//	}
//
//
//}
int main()
{
	int N;
	TriesNode tries1;
	cin >> N >> T;
	string word;
	for (int i = 0; i < 26; i++)
	{
		tries1.child[i] = NULL;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> word;
		words.push_back(word);
		insertTrie(&tries1, word);
	}
	int total = 0;
	findPrefix(&tries1, "", total);
	cout << "prefix:\n";
	for (int i = 0; i < prefixes.size(); i++) {
		cout << prefixes[i] << "\n";
	}
	cout << "suffix:\n";
	for (int i = 0; i < 26; i++)
	{
		tries1.child[i] = NULL;
	}
	for (int i = 0; i < N; i++)
	{
		insertReverseTrie(&tries1, words[i]);
	}
	prefixes.clear();
	total = 0;
	findsuffix(&tries1, "", total);
	sort(prefixes.begin(), prefixes.end());
	for (int i = 0; i < prefixes.size(); i++) {
		cout << prefixes[i] << "\n";
	}
	return 0;
}
#endif