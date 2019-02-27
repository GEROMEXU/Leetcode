#include <iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
#include <sstream>
using namespace std;
class Solution1 {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> result;
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]] = i;
		}
		for (int i = 0; i < findNums.size(); i++) {
			bool found = false;
			for (int j = m[findNums[i]]; j < nums.size(); j++) {
				if (nums[j] > findNums[i]) {
					result.push_back(nums[j]);
					found = true;
					break;
				}
			}
			if (!found) {
				result.push_back(-1);
				found = false;
			}

		}
		return result;
	}
};
class Solution2 {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> result;
		stack<int> s;
		map<int, int> m;
		for (int i = nums.size() - 1; i >= 0; i--) {
			while (!s.empty() && s.top() <= nums[i])
				s.pop();
			m[nums[i]] = s.empty() ? -1 : s.top();
			s.push(nums[i]);
		}
		for (int i = 0; i < findNums.size(); i++)
			result.push_back(m[findNums[i]]);
		return result;
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums1 = stringToIntegerVector(line);
		getline(cin, line);
		vector<int> nums2 = stringToIntegerVector(line);

		vector<int> ret = Solution1().nextGreaterElement(nums1, nums2);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}