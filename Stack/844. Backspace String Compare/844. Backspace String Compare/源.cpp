#include <iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<assert.h>
using namespace std;
class Solution1 {
public:
	bool backspaceCompare(string S, string T) {
		stack<char> s1;
		stack<char> s2;
		bool flag = true;

		int i = 0, j = 0;
		while (i < S.length())
		{
			if (S[i] == '#' && !s1.empty())
			{
				s1.pop();
			}
			else if(S[i] != '#')
			{
				s1.push(S[i]);
			}
			i++;
		}

		while (j < T.length())
		{
			if (T[j] == '#' && !s2.empty())
			{
				s2.pop();
			}
			else if (T[j] != '#')
			{
				s2.push(T[j]);
			}
			j++;
		}
		if (s1.size() == s2.size())
		{
			while (!s1.empty() && !s2.empty())
			{
				if (s1.top() == s2.top())
				{
					s1.pop();
					s2.pop();
				}
				else
				{
					flag = false;
					break;
				}
			}
			return flag;
		}
		else
		{
			flag = false;
			return flag;
		}
	}
};
class Solution2 {
public:
	bool backspaceCompare(string S, string T) {
		int i = S.length() - 1, j = T.length() - 1;
		while (1) {
			for (int back = 0; i >= 0 && (back || S[i] == '#'); --i)
				back += S[i] == '#' ? 1 : -1;
			for (int back = 0; j >= 0 && (back || T[j] == '#'); --j)
				back += T[j] == '#' ? 1 : -1;
			if (i >= 0 && j >= 0 && S[i] == T[j])
				i--, j--;
			else
				return i == -1 && j == -1;
		}
	}
};


string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		string S = stringToString(line);
		getline(cin, line);
		string T = stringToString(line);

		//bool ret1 = Solution1().backspaceCompare(S, T);
		bool ret2 = Solution2().backspaceCompare(S, T);

		//string out1 = boolToString(ret1);
		string out2 = boolToString(ret2);
		//cout <<"Mine:"<< out1 << endl;
		cout << "Others:" << out2 << endl;
	}
	return 0;
}