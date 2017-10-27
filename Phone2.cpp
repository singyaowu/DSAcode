//#define Phonebook2
#ifdef Phonebook2
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string>phone;
int main()
{
	int N;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i<N; i++)
	{
		int operation;
		cin >> operation;
		switch (operation)
		{
		case 1:
		{
			string temp;
			cin >> temp;
			phone.push_back(temp);
			break;
		}
		case 2:
		{
			string phone1, phone2;
			cin >> phone1>> phone2;
			sort(phone.begin(), phone.end());
			long long int total = (upper_bound(phone.begin(), phone.end(), phone2)
				- lower_bound(phone.begin(), phone.end(), phone1));
			cout << total <<"\n";
			break;
		}
		default:
			break;
		}
	}
	return 0;
}
#endif
