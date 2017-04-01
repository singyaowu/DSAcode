#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iterator>  
using namespace std;
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
struct Data
{
	long long frequency;
	char* index;
	Data(long long fre, char* ind) {
		frequency = fre;
		index = ind;
	}
};
struct TriesNode 
{
	TriesNode* child[26];
	vector<int> position[5];//set_intersection
	bool isWord;
};
struct FreCompare {
	bool operator()(const Data &q1, const Data &q2)const {
		return(q1.frequency > q2.frequency);
	}
};
vector<int>* searchTree(TriesNode *N, string word, int positionInLine)
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
			return NULL;
		}
	}
	if (triesNodeNow->isWord) {
		return &(triesNodeNow->position[positionInLine]);
	}
	else {
		return NULL;
	}
}

void insertTrie(TriesNode *triesNode, string charcacter, int positionInLine, int indexLine)
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
	triesNodeNow->position[positionInLine].push_back(indexLine);
}

void saveDictionary(char dictionary[], const char* address, const int n, vector <char*> &Nphrase,/*vector<long> &frequencyvector<Data> &NphraseFre,*/TriesNode &tree)

{
	FILE *fp;
	char* temp = dictionary;
	//int countSpace = 0;
	int indexLine = 0;
	fp = fopen(address, "r");
	//long long tmp = fread(dictionary, sizeof(char), 373395795, fp);
	int tmp = fread(dictionary, sizeof(char), 39956, fp);//********TEST USE********TEST USE****************TEST USE******TEST USE******TEST USE
	for (int i = 0; i < 26; i++)
	{
		tree.child[i] = NULL;
	}
	string word[5];
	for (int i = 0; i < n; i++) 
		word[i] = "";	
	int indexSpace = 0;
	bool triggerTab = false;
	for (long i = 0; i < tmp; i++) {
		if (dictionary[i] != ' ' && dictionary[i] != '\t'&& triggerTab == false) {
			/*word[indexSpace][indexWord] = temp[j];*/
			word[indexSpace] += dictionary[i];
			/*indexWord++;*/
		}
		else if (dictionary[i] == ' ') {
			//means I have save a word and indexSpace indicates the position of word
			//buildtries
			//word[indexSpace][indexWord] = '\0';
			//word[indexSpace] += '\0';
			insertTrie(&tree, word[indexSpace], indexSpace, indexLine);
			indexSpace++;
			/*indexWord = 0;*/
		}
		else if (dictionary[i] == '\t') {
			triggerTab = true;
			insertTrie(&tree, word[indexSpace], indexSpace, indexLine);
		}
		else if (dictionary[i] == '\n') {
			dictionary[i] = '\0';
			//frequencyString += '\0';
			//Data tempdata(stoll(frequencyString), temp);
			////frequency.push_back(stol(frequencyString));
			//////save pointer of each line
			Nphrase.push_back(temp);
			/*NphraseFre.push_back(tempdata);*/
			//cout << i << "\n";//*********TEST USE********TEST USE****************TEST USE******TEST USE******TEST USE
			temp = &(dictionary[i+1]);
			indexLine++;
			for (int j = 0; j < n; j++)	word[j] = "";
			indexSpace = 0;
			triggerTab = false;
			/*frequencyString = "";*/
		}
		/*else if (triggerTab) {
			frequencyString += dictionary[i];	
		}*/
#ifdef OLD
			for (int i = 0; i < n; i++) {
				word[i] = "";
			}
			
			/*int indexWord = 0;*/
			int indexSpace = 0;
			bool triggerTab = false;
			//collect words
			for (int j = 0; j < phraseLength; j++) {
				//char wordTemp[20];
				if(temp[j] != ' ' && temp[j] != '\t'&& triggerTab == false) {
					/*word[indexSpace][indexWord] = temp[j];*/
					word[indexSpace] += temp[j];
					/*indexWord++;*/
				}
				else if(temp[j] == ' '){
					//means I have save a word and indexSpace indicates the position of word
					//buildtries
					/*word[indexSpace][indexWord] = '\0';*/
					word[indexSpace] += '\0';
					insertTrie(&tree,word[indexSpace],indexSpace,indexLine);
					indexSpace++;
					/*indexWord = 0;*/
				}
				else if (temp[j] == '\t') {
					triggerTab = true;
				}
				else if (triggerTab) {
					int indexfre = 0;
					for (int k = j; k < phraseLength; k++) {
						frequencyString[indexfre] = temp[k];
						indexfre++;
					}
					frequencyString[indexfre] = '\0';
					break;
				}			
			}
			//store frequency
			frequency.push_back(atol(frequencyString));
			//save pointer of each line
			Nphrase.push_back(temp);
			//to the next line.
			cout << i << "\n";
			++i;
			temp = &dictionary[i];
			indexLine++;
			//for (int d = 0; d < n; d++)
			//{
			//	delete [] word[d];
			//}
			//delete [] word;
#endif // OLD
		}
	}	

void expandQuery(const string query, vector<string> &expandedQueries)
{	
	//find "?"
	int questionMarkPostion;// = query.find('?');
	int slashPostion;// = query.find('/');
	int starPosition;
	if ((questionMarkPostion = query.find('?')) != -1) {
		string copiedQuery(query);
		copiedQuery.erase(questionMarkPostion, 1);
		expandQuery(copiedQuery, expandedQueries);
		int sapcePosition = copiedQuery.find(' ', questionMarkPostion);
		copiedQuery.erase(questionMarkPostion, sapcePosition - questionMarkPostion + 1);//+1是為了只留下一個" "
		expandQuery(copiedQuery, expandedQueries);
	}
	//find "/"
	else if ((slashPostion = query.find('/')) != -1) {
		string copiedQuery(query);
		copiedQuery.erase(slashPostion, 1);
		int lastSapcePosition = slashPostion - 1;
		while (lastSapcePosition > 0 && copiedQuery[lastSapcePosition - 1] != ' ') {
			lastSapcePosition--;
		}
		int nextSapcePosition = copiedQuery.find(' ', slashPostion);
		string secondCopied(copiedQuery);
		copiedQuery.erase(slashPostion, nextSapcePosition - slashPostion );
		expandQuery(copiedQuery, expandedQueries);
		secondCopied.erase(lastSapcePosition, slashPostion - lastSapcePosition);
		expandQuery(secondCopied, expandedQueries);
	}
	//find "*"
	else if ((starPosition = query.find('*')) != -1) {
		string copiedQuery(query);
		int numWord = 0;
		int numStar = 0;
		int length = copiedQuery.length();
		for (int i = 0; i < length; i++) {//字的個數剛好等於空白個數
			if (copiedQuery[i] == ' ') {
				numWord++;
			}
			else if (copiedQuery[i] == '*') {
				numStar++;
			}
		}
		numStar--;//減去現在處理掉的*
		numWord = 5 - numWord + numStar; //可插" _ "的數目，即5 - (numWord - numStar)
		copiedQuery.erase(starPosition, 2);//順便刪掉後面的" "
		if (numWord < 4) {//也就是只有一個字 不符合規則 一定要有至少兩個字
			expandQuery(copiedQuery, expandedQueries);
		}
		for (int i = 0; i < numWord; i++) {
			copiedQuery.insert(starPosition, "_ ");//至少可以放一個"_ "
			expandQuery(copiedQuery, expandedQueries);
		}
	}
	else {
		expandedQueries.push_back(query);
	}	
}

void searchQuery(const vector<string> &expandedQueries, TriesNode N[], vector <int> indexMatchForLines[], vector <char*> Nphrase[4])
{
	int numExpandedQueries = expandedQueries.size();
	for (int numExpTest = 0; numExpTest < numExpandedQueries; numExpTest++) {
		string expandString = expandedQueries[numExpTest];
		int numN = 0;
		string word[5];
		int length = expandString.length();
		int assignPosition = 0;
		for (int j = 0; j < length; j++) {
			if (expandString[j] == ' ') {
				word[numN].assign(expandString, assignPosition, j - assignPosition);
				assignPosition = j + 1;
				numN++;//空白數	可能值為1,2,3,4
			}
			else if (j == length - 1)//句子底
			{
				word[numN].assign(expandString, assignPosition, j - assignPosition + 1);
				assignPosition = j + 1;
				numN++;//空白數	可能值為1,2,3,4
			}
		}
		vector<int>* listToIntersection[5];//set_intersection
		int indexMaxList = -1;
		for (int i = 0; i < numN; i++) {
			if (word[i] != "_") {//在迴圈裡indexMaxList是非token字數減一
				indexMaxList++;
				listToIntersection[indexMaxList] = searchTree(&N[numN - 2], word[i], i);
				if (listToIntersection[indexMaxList] == NULL) 
					break;
			}
		}
		indexMaxList++;//此時indexMaxList代表意義直接為對非token字作了搜尋次數
		vector<int> intersectionList;
		if (indexMaxList > 1) {//至少兩個(indexMaxList=1代表對非token字作了一次搜尋,=0代表沒做)
			vector<int>::iterator it;
			intersectionList.reserve(10);
			//it = set_intersection(listToIntersection[0]->begin(), listToIntersection[0]->end(),
			//	listToIntersection[1]->begin(), listToIntersection[1]->end(), intersectionList.begin());
			set_intersection(listToIntersection[0]->begin(), listToIntersection[0]->end(),
				listToIntersection[1]->begin(), listToIntersection[1]->end(),back_inserter(intersectionList));
			/*intersectionList.resize(it - intersectionList.begin());*/
			for (int i = 2; i < indexMaxList; i++) {
				it = set_intersection(intersectionList.begin(), intersectionList.end(),
					listToIntersection[i]->begin(), listToIntersection[i]->end(), intersectionList.begin());
				intersectionList.resize(it - intersectionList.begin());
			}
			indexMatchForLines[numN-2].insert(indexMatchForLines[numN-2].end(), intersectionList.begin(), intersectionList.end());
		}
		else if (indexMaxList == 1 && listToIntersection[0] != NULL) {//只有一個
			/////*vector<int> intersectionList = *listToIntersection[0];*/
			indexMatchForLines[numN-2].insert(indexMatchForLines[numN-2].end(),
				listToIntersection[0]->begin(), listToIntersection[0]->end());
		}
		else {//沒有list 全部都是"_ _ _..."或根本是NULL
			/**新加的*/
			if (indexMaxList == 0) {
				long long NumNphrase = Nphrase[numN - 2].size();
				for (int time = 0; time < NumNphrase; time++) {
					indexMatchForLines[numN - 2].push_back(time);
				}
			}
		}
	}
		
		for (int i = 0; i < 4; i++) {
			if (indexMatchForLines[i].size() > 0) {
				vector<int>::iterator it;
				sort(indexMatchForLines[i].begin(), indexMatchForLines[i].end());
				it = unique(indexMatchForLines[i].begin(), indexMatchForLines[i].end());
				indexMatchForLines[i].resize(distance(indexMatchForLines[i].begin(), it));
			}			
		}
}
char dictionary[4][373395800];
int main(int argc, char *argv[])
{
#pragma region  Save
	//vector <Data>  NphraseFre[4];
	
	vector <char*> Nphrase[4];
	//vector <long> frequency[4];
	TriesNode N[4];
	string path2 = string(argv[1]) + "2gm.small.txt";
	string path3 = string(argv[1]) + "3gm.small.txt";
	string path4 = string(argv[1]) + "4gm.small.txt";
	string path5 = string(argv[1]) + "5gm.small.txt";

	saveDictionary(dictionary[0], path2.c_str(), 2, Nphrase[0], N[0]);
	saveDictionary(dictionary[1], path3.c_str(), 3, Nphrase[1], N[1]);
	saveDictionary(dictionary[2], path4.c_str(), 4, Nphrase[2], N[2]);
	saveDictionary(dictionary[3], path5.c_str(), 5, Nphrase[3], N[3]);

#pragma endregion
	//input queries
	string query;
	vector<string> expandedQueries;
	expandedQueries.reserve(20);
	while (getline(cin, query))
	{
		cout << "query: " << query << endl << "output: ";
		int numOutput;
		vector <int> indexMatchForLines[4];
		expandQuery(query, expandedQueries);
		searchQuery(expandedQueries, N, indexMatchForLines, Nphrase);
		//compute frequency
		vector<Data> indexSatis;
		for (int i = 0; i < 4; i++) {
			vector<int>::iterator it;
			for (it = indexMatchForLines[i].begin(); it != indexMatchForLines[i].end(); ++it) {///////////////////**/+++++++++++
				char* tempLine = Nphrase[i][*it];
				char frequencyString[15];
				int lengthLine = strlen(tempLine);
				int tabpos;
				for (int k = 0; k < lengthLine; k++) {///////PROBLEM!!!!!!!!!!!!
					if (tempLine[k] == '\t') {
						tabpos = k;
						break;
					}
				}
				int indexFre = 0;
				for (int k = tabpos + 1; k < lengthLine; k++) {
					frequencyString[indexFre] = tempLine[k];
					indexFre++;
				}
				frequencyString[indexFre] = '\0';
				Data tempData(atoll(frequencyString), tempLine);
				indexSatis.push_back(tempData);
			//	if (frequency[i][*it] > temp) {
			//		temp = frequency[i][*it];
			//		index.push_back(Nphrase[i][*it]);			
				//由字母順序排列
				//else if (frequency[i][*it] = temp) {
				//	index.push_back(Nphrase[i][*it]);
				//	if (index.end()[0] < index[index.size - 2][0]) {
				//		char* tempory;
				//		tempory = *index.end();
				//		*index.end() = index[index.size - 2];
				//		index[index.size - 2] = temp;
				//	}	
				//}
			}
		}
		sort(indexSatis.begin(), indexSatis.end(), FreCompare());
		if ((numOutput = indexSatis.size()) > 5) {
			numOutput = 5;	
			cout << numOutput << endl;
			/*vector<char*>::iterator it = indexSatis.end() - 1;*/
			for (int i = 0; i < 5; i++) {
				cout << indexSatis[i].index << endl;
				/*it--;*/
			}
		}
		else {
			cout << numOutput << endl;
		//	vector<char*>::iterator it;
		//	for (it = index.end() - 1; it != index.begin() ; it--) {
		//		cout << *it << endl;
		//	}
		//	cout << *(index.begin()) << endl;
			for (int i = 0; i < numOutput; i++) {
				cout << indexSatis[i].index << endl;
				/*it--;*/
			}
		}
		expandedQueries.clear();
	}
	return EXIT_SUCCESS;
}

