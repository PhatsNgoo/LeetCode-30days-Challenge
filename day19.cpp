#include "main.h"
#include <iostream>

using namespace std;

int Solution::search(vector<int> &nums, int target)
{
	if (nums.size() == 0)
		return -1;
	if (target < nums[0])
	{
		for (int i = nums.size() - 1; i > 0; i--)
		{
			if (nums[i] == target)
			{
				return i;
			}
		}
	}
	else
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target)
			{
				return i;
			}
		}
	}
	return -1;
}

int main()
{
	return 0;
}