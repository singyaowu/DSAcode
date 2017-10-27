//#define STAY
#ifdef STAY
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <unordered_map>
using namespace std;
struct studentID 
{
	string beforeID;
	string backID;
};
studentID students [200000];
string queue[200000];
int main()
{
	int n;
	cin >> n;
	unordered_map<string, string> studentFirstMap;
	unordered_map<string, string> studentSecondMap;
	int lastPersonIndex;
	for (int i = 0; i < n; i++)
	{
		cin >> students[i].beforeID >> students[i].backID;
		if (students[i].backID == "0") {
			lastPersonIndex = i;
		}
		studentFirstMap[students[i].beforeID] = students[i].backID;
		studentSecondMap[students[i].backID] = students[i].beforeID;
	}
	queue[1] = studentFirstMap["0"];
	int indexNow = 1;
	int studentCountIndex;
	while (true) {
		string tempS = studentFirstMap[queue[indexNow]];
		studentFirstMap.erase(queue[indexNow]);
		studentSecondMap.erase(tempS);
		if (tempS == "0") { ++indexNow; studentCountIndex = indexNow; break; }
		if (tempS == "") { studentCountIndex = indexNow; --indexNow; break; }
		indexNow += 2;
		queue[indexNow] = tempS;
	}
	if (studentCountIndex != indexNow) {//°¸¼Æ
		queue[indexNow] = students[lastPersonIndex].beforeID;
		while (indexNow > 1) {
			string tempS = studentSecondMap[queue[indexNow]];
			if (tempS == "0") { ++indexNow; break; }
			if (tempS == "") { --indexNow; break; }
			indexNow -= 2;
			queue[indexNow] = tempS;
		}
	}
	else {//©_¼Æ
		deque<string> queueTemp;
		for (auto &n : studentFirstMap) {
			if(n)
		}
	}
	for (int i = 0; i < studentCountIndex; i++) {
		cout << queue[i] << ' ';
	}
	cout << queue[studentCountIndex] << '\n';
	cout << n - studentCountIndex - 1;
	
	return 0;
}
#endif