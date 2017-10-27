//#define wizard
#ifdef wizard
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string phrase;
		stack<char> stackr;
		getline(cin, phrase);
		int size = phrase.size();
		string answer;
		for (int j = 0; j < size; j++)
		{
			char c = phrase[j];
			if (c == ' ')
				continue;
			else if (c == '+' || c == '-')
			{
				if (stackr.empty())
				{
					stackr.push(c);
				}
				else
				{
					while(!stackr.empty() && stackr.top() != '(')
					{
						//cout << stackr.top() << ' ';
						answer += stackr.top();
						stackr.pop();
					}
					stackr.push(c);				
				}
			}
			else if (c == '*' || c == '/')
			{
				if (stackr.empty())
				{
					stackr.push(c);
				}
				else
				{
					while(!stackr.empty() && (stackr.top() == '*' || stackr.top() == '/'))
					{
						//cout << stackr.top() << ' ';
						answer += stackr.top();
						stackr.pop();
					}
					stackr.push(c);
				}
			}
			else if (c == '(')
			{
				stackr.push(c);
			}
			else if (c == ')')
			{
				while (stackr.top() != '(')
				{
					//cout << stackr.top() << ' ';
					answer += stackr.top();
					stackr.pop();
				}
				stackr.pop();//to pop '('
				
			}
			else if (c >= '0'&&c <= '9')
			{
				string number;
				number = c;
				while (j + 1 < size &&  phrase[j + 1] >= '0' && phrase[j + 1] <= '9')
				{
					j++;
					number += phrase[j];
				}
				answer += (number + ' ');
			}
		}
		while (!stackr.empty())
		{
			//cout << stackr.top() << ' ';
			answer += stackr.top();
			stackr.pop();
		}
		int sizeAns = answer.size();
		for (int j = 0; j < sizeAns; j++)
		{
			char c = answer[j];
			if (c >= '0'&&c <= '9')
			{
				string number;
				number = c;
				while (j + 1 < sizeAns &&  answer[j + 1] >= '0' && answer[j + 1] <= '9')
				{
					j++;
					number += answer[j];
				}
				j++;
				if (j < sizeAns - 1)
					cout << number << ' ';
				else
					cout << number;
			}
			else
			{
				if (j < sizeAns - 1)
					cout << c << ' ';
				else
					cout << c;
			}
		}
		if (i != n - 1)
			cout << '\n';
	}
	return 0;
}
#endif