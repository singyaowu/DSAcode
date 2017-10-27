//#define SAD
#ifdef SAD
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		vector<int> query;
		stack<int> SBM;
		int temp;
		cin >> temp;
		int min = temp;
		int minIndex = 0;
		int maxIndex = 0;
		int idex = 0;
		int max = temp;
		while (temp != -1) {
			if (temp > max)
			{
				max = temp;
				maxIndex = idex;
			}
			else if (temp < min)
			{
				min = temp;
				minIndex = idex;
			}
			query.push_back(temp);
			SBM.push(temp);
			cin >> temp;
			idex++;
		}
		bool isSAD = false;
		if (minIndex < maxIndex)
		{
			for (int j = maxIndex + 1; j < query.size(); j++)
			{
				if (query[j] < max && query[j] > min) {
					isSAD = true;
					break;
				}
			}
		}
		else {
			for (int l = 1; l < 2; l++) {
				for (int j = 0; j < query.size(); j++)
				{
					bool stage1 = false;
					//bool stage2 = false;
					if (j + l + 1 < query.size()) {
						if (query[j] < query[j + l] && query[j + l]> query[j + l + 1])
						{
							stage1 = true;
						}
						if (stage1) {
							for (int k = j + l + 1; k < query.size(); k++)
							{
								if (query[k] < query[j + l] && query[k] > query[j])
								{
									isSAD = true;
									break;
								}
							}
						}
						if (isSAD)break;
					}
				}
				if (isSAD)break;
			}
		}
		/*//while (!SBM.empty())
		//{
		//	int firstTop, secondTop, thirdTop;
		//	firstTop = SBM.top();
		//	SBM.pop();
		//	secondTop = SBM.top();
		//	SBM.pop();
		//	thirdTop = SBM.top();
		//	SBM.pop();
		//	if (firstTop<secondTop&&secondTop>thirdTop&&thirdTop < firstTop){//¤p¤j¤¤
		//		isSAD = true; break;
		//	}
		//	else if (firstTop<secondTop&&secondTop>thirdTop&&thirdTop < firstTop) {

		//	}
		//	else if (firstTop<secondTop&&secondTop>thirdTop&&thirdTop < firstTop) {

		//	}
		//	else if (firstTop<secondTop&&secondTop>thirdTop&&thirdTop < firstTop) {

		//	}
		//	else if (firstTop<secondTop&&secondTop>thirdTop&&thirdTop < firstTop) {

		//	}
		//	else if (firstTop<secondTop&&secondTop>thirdTop&&thirdTop < firstTop) {

		//	}
		//	else {

		//	}
		//}
		*/
		if (isSAD) {
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
	}


	return 0;
}

#endif