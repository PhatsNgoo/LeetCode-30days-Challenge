#include "main.h"
#include <map>
#include <iostream>
#include <string>
#include <sstream>
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

	int profit = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		/* code */
		if (prices[i] > prices[i - 1])
		{
			/* code */
			profit += prices[i] - prices[i - 1];
		}
	}
	return profit;
}

bool compareTwoAnagram(string first, string second)
{
	if (first.size() != second.size())
		return false;
	int count = 0;
	for (int i = 0; i < first.size(); i++)
	{
		if (second.find(first[i]) != string::npos)
		{
			second.erase(second.begin() + second.find(first[i]));
			count++;
		}
		else
		{
			return false;
		}
	}
	if (count == first.size())
		return true;

	return false;
}
string sortString(string s)
{
	int temp;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			if (s[i] > s[j])
			{
				temp=s[j];
				s[j]=s[i];
				s[i]=temp;
			}
		}
	}
	return s;
}
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
	map<string,vector<string>>map;
	for(string s:strs){
		map[sortString(s)].push_back(s);
	}
	vector<vector<string>>result;
	for(auto p:map){
		result.push_back(p.second);
	}
	return result;
}
int main()
{
	vector<string> vtrString = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> result = groupAnagrams(vtrString);
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i].size() > 1)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << "/";
			}
			cout << endl;
		}
	}
	// string test="gsdfgsdfgasd";
	// string result=sortString(test);
	// cout<<result;
	// string first="converter";
	// string second="contrived";
	// if(compareTwoAnagram(first,second)){
	// 	cout<<"true";
	// }

	return 0;
}