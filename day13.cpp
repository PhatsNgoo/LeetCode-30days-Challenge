#include "main.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int Solution::findMaxLength(vector<int> &nums)
{
	map<int,int> mp;
	mp[0]=-1;
	int length = 0;
	int count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		// count=count +nums[i]==1?1:-1;
		if(nums[i]==1) count++;
		else	count--;
		if (mp.find(count) != mp.end())
		{
			length=max(length,i-mp[count]);
		}
		else
		{
			mp[count]=i;
		}
	}
	return length;
}

int main()
{
	Solution solution;
	vector<int> input = {0,0,1};
	int res = solution.findMaxLength(input);
	cout << res;
	return 0;
}