#ifdef  zhohgiz

#include<iostream>
#include<climits>
using namespace std;

int imax = INT_MAX - 10;
int plans[10]; //幾種粽子組合
int numberOfPlans;
int maxNumber = 10000000;
int d[10000000]; //存放各種組合
int count[10000000][10];
void initD() {
	for (int i = 0; i<maxNumber; i++) {
		for (int j = 0; j<numberOfPlans; j++)count[i][j] = 0;
	}
	for (int i = 0; i<maxNumber; i++) {
		d[i] = imax;
	}
};
//DP
void min_Plans() {
	for (int i = 0; i<maxNumber; i++) {
		if (i == 0) {
			d[0] = 0;
			continue;
		}
		int MIN = imax;
		for (int j = 0; j<numberOfPlans; j++) {
			if (i >= plans[j]) {
				if (d[i - plans[j]] + 1 <= MIN) {
					MIN = d[i - plans[j]] + 1;
					for (int k = 0; k<numberOfPlans; k++)
						count[i][k] = count[i - plans[j]][k];
					count[i][j]++;
				}
			}
			else
				break;
			d[i] = MIN;
		}
	}
}

int main() {
	int operations;
	cin >> operations;
	cin >> numberOfPlans;
	for (int i = 0; i<numberOfPlans; ++i) {
		cin >> plans[i];
	}
	initD();
	min_Plans();
	for (int i = 0; i<operations; ++i) {
		int instruction;
		cin >> instruction;
		switch (instruction) {
			int targetNumber;
		case 1: {
			cin >> targetNumber;
			//targetNumber += 1;
			int totalZ = 0;
			if (d[targetNumber] != imax) {
				for (int i = 0; i<numberOfPlans; i++) {
					totalZ += count[targetNumber][i];
				}
				cout << totalZ << '\n';
			}
			else {
				cout << "-1\n";
			}
			break;
		}
		case 2: {
			cin >> targetNumber;
			targetNumber += 1;
			for (int k = 0; k<targetNumber; k++) {
				if (d[k] == imax) {
					cout << k << '\t';
				}
			}
			break;
		}
		}
	}
	return 0;
}
#endif