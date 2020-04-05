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

	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		if (sum < nums[i])
		{
			sum = nums[i];
		}
		if (result < sum)
		{
			result = sum;
		}
	}
	return result;
}

void Solution::moveZeroes(vector<int> &nums)
{
	int size = nums.size();
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (nums[index] == 0)
		{
			nums.push_back(nums[index]);
			nums.erase(nums.begin() + index);
			index--;
		}
		index++;
	}
}

int Solution::maxProfit(vector<int> &prices)
{
	if (prices.empty())
	{
		/* code */
		return 0;
	}
	
	int profit=0;
	for (int i=1;i<prices.size();i++)
	{
		/* code */
		if (prices[i]>prices[i-1])
		{
			/* code */
			profit+=prices[i]-prices[i-1];
		}
		
	}
	return profit;
}
int main()
{
	vector<int> input = {7,1,5,3,6,4};
	int profit=solution.maxProfit(input);
	cout<<profit;
	return 0;
}