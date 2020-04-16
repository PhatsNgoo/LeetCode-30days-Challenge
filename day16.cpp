#include "main.h"
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool Solution::checkValidString(string s)
{
	int lo = 0;
	int hi = 0;
	for (char c : s)
	{
		lo += c == '(' ? 1 : -1;
		hi += c != ')' ? 1 : -1;
		if (hi < 0)
			break;
		lo = max(lo, 0);
	}
	return lo == 0;
}

int main()
{
	Solution solution;
	string input = "(*(())(()*))";
	bool res = solution.checkValidString(input);
	cout << res;
	return 0;
}