#include "main.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <stddef.h>

bool Solution::backspaceCompare(string s, string t)
{
	string sResult;
	string tResult;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '#')
		{
			s.erase(s.begin() + i);
			if (i - 1 >= 0)
			{
				s.erase(s.begin() + i - 1);
				i -= 2;
			}
			else
			{
				i--;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] == '#')
		{
			t.erase(t.begin() + i);
			if (i - 1 >= 0)
			{
				t.erase(t.begin() + i - 1);
				i -= 2;
			}
			else
			{
				i--;
			}
		}
	}
	return s == t;
}
//Better solution with O(N)
bool betterSolution(string S,string T)
{
	int i = S.length() - 1, j = T.length() - 1, back;
        while (true) {
            back = 0;
            while (i >= 0 && (back > 0 || S[i] == '#')) {
                back += S[i] == '#' ? 1 : -1;
                i--;
            }
            back = 0;
            while (j >= 0 && (back > 0 || T[j] == '#')) {
                back += T[j] == '#' ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && S[i] == T[j]) {
                i--;
                j--;
            } else {
                break;
            }
        }
        return i == -1 && j == -1;
}
Solution solution;
int main()
{
	bool test = solution.backspaceCompare("a##c", "#a#c");
	cout << test;
	return 0;
}