//#define Cal
#ifdef Cal
#include <iostream>
#include <string>
#include <stack>
#include <complex>
using namespace std;
complex<float> trnasform(string query, int &i)
{
	string a[2] = { "" ,"" };
	complex<float> first;
	int ri = 0;
	int firstindex = i;
	while (1){
		if (query[i] == '+'){
			ri++;
		}
		else if (query[i] == '-'){
			if (i != firstindex){
				ri++;
				a[ri] += '-';
			}
			else
			{
				a[0] += '-';
			}
		}
		else if (query[i] == 'i'){
			if (a[1] == "" && a[0] != ""&& ri == 0) {//XXi
				first = complex<float>(0, atoi(a[0].c_str()));
			}
			else if (a[0] != ""&& a[1] == "" && ri == 1) {//XXX+i
				a[1] += '1';
				first = complex<float>(atoi(a[0].c_str()), atoi(a[1].c_str()));
			}
			else if (a[1] == "" && (a[0] == "" || a[0] == "-")) {//i,-i
				a[0] += '1';
				first = complex<float>(0, atoi(a[0].c_str()));
			}

			else{//XX+XXi XX-XXi
				first = complex<float>(atoi(a[0].c_str()), atoi(a[1].c_str()));
			}
			i++;
			break;
		}
		else if (query[i] == ']'){
			if (a[1] == "")
			{
				first = complex<float>(atoi(a[0].c_str()), 0);
			}break;
		}
		else{
			a[ri] += query[i];
		}i++;
	}
	return first;
}
complex<float> calculate(string query)
{
	complex<float> first;
	complex<float> second;
	stack <complex<float>> stackr;
	for (int i = 0; i < query.size(); ++i)
	{
		if (query[i] == '[')
		{
			i++;	
			first = trnasform(query, i);
			stackr.push(first);
		}
		else if (query[i] == '+')
		{
			second = stackr.top();
			stackr.pop();
			first = stackr.top();
			stackr.pop();
			stackr.push((first + second));
		}
		else if (query[i] == '-')
		{
			second = stackr.top();
			stackr.pop();
			first = stackr.top();
			stackr.pop();
			stackr.push((first - second));
		}
		else if (query[i] == '*')
		{
			second = stackr.top();
			stackr.pop();
			first = stackr.top();
			stackr.pop();
			stackr.push((first * second));
		}
		else if (query[i] == '/')
		{
			second = stackr.top();
			stackr.pop();
			first = stackr.top();
			stackr.pop();
			stackr.push((first / second));
		}
	}
	return stackr.top();
}
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
					while (!stackr.empty() && stackr.top() != '(')
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
					while (!stackr.empty() && (stackr.top() == '*' || stackr.top() == '/'))
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
			else if (c == '[')
			{
				string number;
				number = c;
				while (j + 1 < size &&  phrase[j] != ']')
				{
					j++;
					number += phrase[j];
				}
				answer += (number);
			}
		}
		while (!stackr.empty())
		{
			//cout << stackr.top() << ' ';
			answer += stackr.top();
			stackr.pop();
		}
		cout << answer << '\n';
		complex<float>answerCom = calculate(answer);
		float Re = answerCom.real();
		float Im = answerCom.imag();
		char cc[16];
		string answerString = "[";
		if (Re != 0) {
			sprintf(cc, "%g", Re);
			answerString += cc;
		}
		if (Re != 0 && Im > 0) {
			answerString += '+';
		}
		if (Im != 0 && Im != 1 && Im != -1) {
			sprintf(cc, "%g", Im);
			answerString += cc;
			answerString += +"i]";
		}
		else if(Im == 0 && Re == 0){
			answerString += "0]";
		}
		else if (Im == 0 && Re != 0) {
			answerString += "]";
		}
		else if (Im == 1) {
			answerString += "i]";
		}
		else if (Im == -1) {
			answerString += "-i]";
		}
		cout << answerString << '\n';
	}
	return 0;
}
#endif