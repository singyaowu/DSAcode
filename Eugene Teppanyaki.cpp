//#define teppa
#ifdef teppa
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int Dp[3000][3000][2];
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string hands;
		cin >> hands;
		int Q;
		cin >> Q;
		int in = 0;
		while (in < hands.size()) {
			if (hands[in] == 'B') {
				hands.erase(in, 1);
			}
			else {
				in++;
			}
		}
		while (hands[0] == 'L'){
			hands.erase(hands.begin());
		}
		while (hands.back() == 'R') {
			hands.erase(hands.size() - 1);
		}
		switch (Q)
		{
		case 1:{
			int uncomfort = 0;
			for (int j = 0; j < hands.size(); j++) {
				if (hands[j] == 'L') {
					if (hands[j - 1] == 'R') {
						uncomfort += 2;
					}
				}
			}
			cout << uncomfort << '\n';
			break;
		}
		case 2: {
			int numL = 0;
			int numAns = 0;
			for (int j = 0; j < hands.size(); ++j) {
				if (hands[j] == 'L') {
					numL++;
				}
			}
			for (int j = 0; j < numL; j++) {
				if (hands[j] == 'R') {
					numAns++;
				}
			}
			cout << numAns << '\n';
			break;
		}
		case 3: {
			int k;
			cin >> k;
			int n = hands.size();
			for (int ai = 0; ai <= n; ai++) {
				for (int j = 0; j <= n - k; j++) {
					Dp[ai][j][0] = INT16_MAX;
					Dp[ai][j][1] = INT16_MAX;
				}
			}
			if (hands[0] == 'R') {
				Dp[1][1][1] = INT16_MAX;
				Dp[1][1][0] = 1;
			}
			else {
				Dp[1][1][1] = 1;
				Dp[1][1][0] = INT16_MAX;;
			}

			for (int ai = 2; ai <= n; ai++) {

				for (int j = 1; j <= ai && j <= n-k; j++)
				{
					if (hands[ai] == 'R') {
						Dp[ai][j][0] = min(min(Dp[ai - 1][j][0], Dp[ai - 1][j - 1][0]), Dp[ai - 1][j - 1][1]);
						Dp[ai][j][1] = Dp[ai - 1][j][1];
					}
					else {
						Dp[ai][j][0] = Dp[ai - 1][j][0];
						Dp[ai][j][1] = min(min(Dp[ai - 1][j][1], Dp[ai - 1][j - 1][0] + 1), Dp[ai - 1][j - 1][1]);
					}
				}
			}
			cout <<2 * min(Dp[n][n - k][0], Dp[n][n - k][1])<<'\n';
			break;
		}
		default:
			break;
		}
	}


	return 0;
}
#endif