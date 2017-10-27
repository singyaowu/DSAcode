//#define GOLD
#ifdef GOLD

#include <iostream>
using namespace std;

unsigned long long dp3[80];
unsigned long long dp4[30];
void dp3Method() 
{
	dp3[0] = 1;
	dp3[1] = 1;
	dp3[2] = 2;
	for (int i = 3; i < 80; i++) {
		dp3[i] = dp3[i - 3] + dp3[i - 1];
	}
}
void dp4Method()
{//	1, 3, 13, 57, 249, 1087, 4745, 20713, 90417, 394691, 1722917, 7520929,
	dp4[0] = 1;
	dp4[1] = 3;
	dp4[2] = 13;
	dp4[3] = 57;
	for (int i = 4; i < 30; i++)
	{
		//a(n) = 5*a(n-1) - 3*a(n-2) + a(n-3)
		dp4[i] = 5 * dp4[i - 1] - 3 * dp4[i - 2] + dp4[i - 3];
	}
}
int main()
{
	int k;
	cin >> k;
	dp3Method();
	dp4Method();
	for (int i = 0; i < k; i++)
	{
		int mi, ni;
		unsigned long long method = 0;
		cin >> mi >> ni;
		switch (mi)
		{
		case 1: {
			method = ni % 3 == 0 ? 1 : 0;
			break;
		}
		case 2: {
			method = ni % 3 == 0 ? 1 : 0;
			break;
		}
		case 3: {
			method = dp3[ni - 1];
			break;
		}
		case 4: {
			if (ni % 3 != 0) {
				break;
			}
			else {
				method = dp4[ni / 3];
			}
			
			break;
		}
		default:
			break;
		}
		cout << method << "\n";
	}
	return 0;
}
#endif