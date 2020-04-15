#include "main.h"
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

vector<int> Solution::productExceptSelf(vector<int> &nums)
{
	vector<int> first;
	first.push_back(1);
	vector<int> second;
	second.push_back(1);
	for (int i = 1; i < nums.size(); i++)
	{
		first.push_back(first[i - 1] * nums[i - 1]);
	}
	for (int i = 1; i < nums.size(); i++)
	{
		second.push_back(second[i - 1] * nums[nums.size() - i]);
	}
	vector<int> result;
	for (int i = 0; i < nums.size(); i++)
	{
		result.push_back(first[i] * second[nums.size() - i - 1]);
	}
	return result;
}

vector<int> betterSolution(vector<int> &nums)
{
	vector<int> output;
	int n = nums.size();
	output.resize(n);
	int res = 1;
	for (int i = 0; i < n; i++)
	{
		output[i] = res;
		res *= nums[i];
	}
	res = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		output[i] *= res;
		res *= nums[i];
	}
	return output;
}

// Magic to boots speed faster ?? :D ?? from 48ms to 40ms
static auto x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return nullptr;
}();
int main()
{
	vector<int> input = {1, 2, 3, 4, 5, 6, 7};
	Solution solution;
	vector<int> output = solution.productExceptSelf(input);
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << "/";
	}
	return 0;
}