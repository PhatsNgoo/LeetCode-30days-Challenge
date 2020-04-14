#include "main.h"
#include <vector>
#include <iostream>
using namespace std;

string shiftLeft(int size, string s)
{
	int count = 0;
	while (count < size)
	{
		s.push_back(s.front());
		s.erase(s.begin());
		count++;
	}
	return s;
}
string shiftRight(int size, string s)
{
	int count = s.size() - 1;
	while (count > s.size() - size - 1)
	{
		s.insert(0, string(1, s.back()));
		s.erase(s.begin() + s.size() - 1);
		count--;
	}
	return s;
}
string Solution::stringShift(string s, vector<vector<int>> &shift)
{
	if (shift[0][0] == 0)
		shift[0][1] *= -1;
	while (shift.size() > 1)
	{
		if (shift[1][0] == 1)
		{
			shift[0][1] += shift[1][1];
			shift.erase(shift.begin() + 1);
			continue;
		}
		else
		{
			shift[0][1] -= shift[1][1];
			shift.erase(shift.begin() + 1);
			continue;
		}
	}
	int shiftSize = (int)shift[0][1] % (int)s.size();
	shiftSize = shiftSize < 0 ? shiftSize * -1 : shiftSize;
	if (shiftSize == 0)
	{
		return s;
	}
	string res;
	if (shift[0][1] < 0)
	{
		res = shiftLeft(shiftSize, s);
	}
	else
	{
		res = shiftRight(shiftSize, s);
	}
	return res;
}
int main()
{
	string test = "abcdefg";
	vector<vector<int>> inputVect = {{1, 1}, {1, 1}, {0, 2}, {1, 3}};
	Solution solution;
	string output = solution.stringShift(test, inputVect);
	cout << endl
		 << output.c_str();
	// int i=-1%3;
	// cout<<i;
	return 0;
}