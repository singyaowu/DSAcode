#define poor
#ifdef poor
#include <iostream>
using namespace std;
long long matrix[26][26];
int M;
void changeLine(long long first[], long long second[])
{
	for (int i = 0; i<M; i++)
	{
		swap(first[i], second[i]);
	}
}
long long countdet()
{
	long long countExch = 0;  //记录行变换的次数（交换）  
	long long value = 1;
	long long q = 0;
	for (int i = 0; i<M; i++)
	{
		if (matrix[i][i] == 0) {
			bool isSingular = true;
			for (int j = i; j < M; j++)
			{
				if (matrix[j][i] != 0)
				{
					changeLine(matrix[i], matrix[j]);//交换两行    
					countExch++;
					isSingular = false;
				}
			}
			if (isSingular)
				return 0;
		}

		for (int j = i + 1; j<M; j++)
		{
			q = -1 * matrix[j][i] / matrix[i][i];

			for (int k = 0; k<M; k++)
			{
				matrix[j][k] = matrix[j][k] + matrix[i][k] * q;
			}
		}
	}
	for (int i = 0; i < M; i++)  //求对角线的积 即 行列式的值  
		value = value * matrix[i][i];
	//行变换偶数次符号不变  
	if (countExch % 2 == 1)
		value *= -1;
	return (value);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> matrix[j][k];
			}
		}
		long long value;
		bool all0 = true;
		for (int j = 0; j < N; j++) {
			if (matrix[j][0] != 0) {
				all0 = false;
				break;
			}
		}
		if (all0) {
			value = 0;
		}
		else
			value = countdet();
		cout << value << '\n';
	}
	
	return 0;
}
#endif