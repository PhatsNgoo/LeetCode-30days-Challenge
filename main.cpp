#include "main.h"
#include <iostream>

using namespace std;
Solution solution;
int Solution::singleNumber(vector<int> &nums)
{
	std::vector<int> tmp(20000, 0);
	std::vector<int> tmpNegative(20000, 0);
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] >= 0)
		{
			tmp[nums[i]] += 1;
		}
		else
		{
			tmpNegative[-nums[i]] += 1;
		}
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == 1)
		{
			return i;
		}
	}
	for (int i = 0; i < tmpNegative.size(); i++)
	{
		if (tmpNegative[i] == 1)
		{
			return -i;
		}
	}
	return 0;
}

int Solution::maxSubArray(vector<int> &nums)
{
	int result = nums[0];
	int sum = 0;
	if (nums.size() == 1)
	{
		return nums[0];
	}
	for (int i = 0; i < nums.size(); i++)
	{
		sum = 0;
		sum += nums[i];
		result = sum > result ? sum : result;
		for (int j = i + 1; j < nums.size(); j++)
		{
			sum += nums[j];
			result = sum > result ? sum : result;
		}
	}
	return result;
}
int main()
{
	vector<int> array = {-2, 1};
	int result = solution.maxSubArray(array);
	std::cout << result;
	return 0;
}