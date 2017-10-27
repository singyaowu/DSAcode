//#define Rank2
#ifdef Rank2
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<double> classNo[300];
vector<int> allClassHeap;
double average[300];
void upHeap(int classNumber)
{
	double temp;
	int posLast = classNo[classNumber].size() - 1;
	while (posLast > 1 && classNo[classNumber][posLast] > classNo[classNumber][posLast / 2]) {
		temp = classNo[classNumber][posLast / 2];
		classNo[classNumber][posLast / 2] = classNo[classNumber][posLast];
		classNo[classNumber][posLast] = temp;
		posLast /= 2;
	}
}
void upHeapbtwClass()
{
	int temp;
	int posLast = allClassHeap.size() - 1;
	while (posLast > 1 && average[allClassHeap[posLast]] > average[allClassHeap[posLast / 2]]) {
		temp = allClassHeap[posLast / 2];
		allClassHeap[posLast / 2] = allClassHeap[posLast];
		allClassHeap[posLast] = temp;
		posLast /= 2;
	}
}
void insertbtwClass(int classIndex)
{
	allClassHeap.push_back(classIndex);
	upHeapbtwClass();
}
void downHeapbtwClass(vector<int> &allClsHp)
{
	int posLast = allClsHp.size() - 1;
	int indexNow = 1;
	allClsHp[1] = allClsHp[posLast];
	allClsHp.pop_back();
	--posLast;
	while (2 * indexNow <= posLast)
	{
		if (average[allClsHp[indexNow]] < average[allClsHp[2 * indexNow]] ||
			(2 * indexNow + 1 <= posLast && average[allClsHp[indexNow]] < average[allClsHp[2 * indexNow + 1]])) {
			if (2 * indexNow + 1 > posLast || average[allClsHp[2 * indexNow]] > average[allClsHp[2 * indexNow + 1]]) {
				swap(allClsHp[2 * indexNow], allClsHp[indexNow]);
				indexNow = 2 * indexNow;
			}
			else {
				swap(allClsHp[2 * indexNow + 1], allClsHp[indexNow]);
				indexNow = 2 * indexNow + 1;
			}
		}
		else {
			break;
		}
	}
}
void downHeap(vector<double> &clsNo)
{
	int posLast = clsNo.size() - 1;
	int indexNow = 1;
	clsNo[1] = clsNo[posLast];
	clsNo.pop_back();
	--posLast;
	while (2 * indexNow <= posLast)
	{
		if (clsNo[indexNow] < clsNo[2 * indexNow] ||
			(2 * indexNow + 1 <= posLast && clsNo[indexNow] < clsNo[2 * indexNow + 1])) {
			if (2 * indexNow + 1 > posLast || clsNo[2 * indexNow] > clsNo[2 * indexNow + 1]) {
				swap(clsNo[2 * indexNow], clsNo[indexNow]);
				indexNow = 2 * indexNow;
			}
			else {
				swap(clsNo[2 * indexNow + 1], clsNo[indexNow]);
				indexNow = 2 * indexNow + 1;
			}
		}
		else {
			break;
		}
	}
}
void insert(int classNumber, double score)
{
	classNo[classNumber].push_back(score);
	upHeap(classNumber);
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		classNo[i].push_back(-1);
	}
	allClassHeap.push_back(-1);
	int I;
	double J;
	cin >> I;
	while (I != -1) {
		cin >> J;
		average[I - 1] += J;
		insert(I - 1, J);
		//classpri[I - 1].push(J);
		cin >> I;
	}
	for (int i = 0; i < N; i++) {
		average[i] /= (classNo[i].size() - 1.0);
		insertbtwClass(i);
	}
	int operation;
	while (1) {
		cin >> operation;
		if (cin.eof()) {
			break;
		}
		switch (operation)
		{
		case 1: {//output the average grade of the class whose average grade is the highest.
			cout << average[allClassHeap[1]] << '\n';
			break;
		}
		case 2: {//t will be followed by u(class). And output the highest grade in this class
			int u;
			cin >> u;
			cout << classNo[u - 1][1] << '\n';
			break;
		}
		case 3: {//it will be followed by m(rank of class), n(rank of grade).
				 //Please find the n - th rank grade in the class whose average grade is the m - th high among all classes.
			int m, n;
			cin >> m >> n;
			if (m == 0)m = 1;
			if (n == 0)n = 1;
			//stack<int> btwClass;
			//stack<double> inClass;
			vector<int> allClsHp = allClassHeap;
			for (int i = 1; i < m; i++) {
				//btwClass.push(allClassHeap[1]);
				downHeapbtwClass(allClsHp);
			}
			vector<double> clsNo = classNo[allClsHp[1]];

			if (n == 0) {
				cout << clsNo[1] << '\n';
			}
			else {
				for (int i = 1; i < n; i++) {
					//inClass.push(classNo[clsInd][1]);
					downHeap(clsNo);
				}
				cout << clsNo[1] << '\n';
				/*while (!inClass.empty()) {
				insert(clsInd, inClass.top());
				inClass.pop();
				}*/
			}
			/*while (!btwClass.empty()) {
			insertbtwClass(btwClass.top());
			btwClass.pop();
			}*/
			break;
		}
		case 4: {//it will be followed by an integer s(class), 
				 //which means that you should output the heap which stores the grades of the class s.
			int s;
			cin >> s;
			s -= 1;
			int size = classNo[s].size();
			for (int i = 1; i < size - 1; ++i) {
				cout << classNo[s][i] << ' ';
			}
			cout << classNo[s][size - 1] << '\n';
			break;
		}
		case 5: {//意思同4，但這次是要你開一個heap依序(此指按照班級的號碼)存取全校每一個班級的平均分數
				 //(平均分數就是把這個班所有學生的分數加總後除以該班的人數)，當出現指令5時，請把這個heap依照level order輸出)
			int size = allClassHeap.size();
			for (int i = 1; i < size - 1; ++i) {
				cout << average[allClassHeap[i]] << ' ';
			}
			cout << average[allClassHeap[size - 1]] << '\n';
			break;
		}
		}
	}
	return 0;
}
#endif