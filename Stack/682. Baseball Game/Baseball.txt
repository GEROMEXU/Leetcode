#include <iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
using namespace std;
class Solution1 {
public:
	int calPoints1(vector<string>& ops) {
		int sum = 0;
		int len = ops.size();
		vector<int> score;
		for (int i = 0; i < len; i++) {
			if (ops[i].compare("D") == 0) {
				score.push_back(score[score.size() - 1] * 2);
			}
			else if (ops[i].compare("C") == 0) {
				score.pop_back();
			}
			else if (ops[i].compare("+") == 0) {
				score.push_back(score[score.size() - 1] + score[score.size() - 2]);
			}
			else {
				score.push_back(stoi(ops[i]));
			}
		}
		for (int j = 0; j < score.size(); j++) {
			sum += score[j];
		}
		return sum;
	}
};
class Solution2 {
public:
	int calPoints2(vector<string>& ops) {
		stack<int> score;
		for (string s : ops) {
			if (s.compare("C") == 0) score.pop();
			else if (s.compare("+") == 0) {
				int one = score.top();
				score.pop();
				int two = score.top();
				score.pop();
				score.push(two);
				score.push(one);
				score.push(one + two);
			}
			else if (s.compare("D") == 0) {
				int one = score.top();
				score.push(2 * one);
			}
			else {
				score.push(stoi(s));
			}
		}
		int sum = 0;
		while (!score.empty()) {
			sum += score.top();
			score.pop();
		}
		return sum;
		//system("pause");
	}

};

int main(){
	string a[5] = { "5","2","C","D","+" };
	vector<string> ops(a,a+5);
	Solution1 s1;
	cout<<s1.calPoints1(ops)<<endl;
	Solution2 s2;
	cout<<s2.calPoints2(ops)<<endl;
	system("pause");
	}


