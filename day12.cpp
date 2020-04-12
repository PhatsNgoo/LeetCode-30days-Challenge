#include "main.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int smashStones(int first, int second)
{
	return first - second;
}
int Solution::lastStoneWeight(vector<int> &stones)
{
	int i;
	int first;
	int second;
	while (stones.size() > 1)
	{
		int firstIndex = stones[0] > stones[1] ? 0 : 1;
		int secondIndex = stones[0] > stones[1] ? 1 : 0;
		first = max(stones[0], stones[1]);
		second = min(stones[0], stones[1]);
		for (i = 2; i < stones.size(); i++)
		{
			if (stones[i] >= first)
			{
				/* code */
				second = first;
				secondIndex = firstIndex;
				first = stones[i];
				firstIndex = i;
			}
			else if (stones[i] > second)
			{
				/* code */
				second = stones[i];
				secondIndex = i;
			}
		}
		if (smashStones(first, second) == 0)
		{
			stones.erase(stones.begin() + secondIndex);
			stones.erase(stones.begin() + firstIndex - 1);
		}
		else
		{
			stones[firstIndex] = smashStones(first, second);
			stones.erase(stones.begin() + secondIndex);
		}
	}
	return stones.size() > 0 ? stones[0] : 0;
}

//Using priority Queue
int betterSolution(vector<int> &stones)
{
	priority_queue<int> q(begin(stones),end(stones));
	while(q.size()>1)
	{
		int first=q.top();
		q.pop();
		int second=q.top();
		q.pop();
		q.push(first-second);
	}
	return q.size() > 0 ? q.top() : 0;
}
int main()
{
	Solution solution;
	vector<int> input = {857, 920, 623, 984, 537, 512, 852, 728, 512, 292, 802, 961, 165, 133};
	int result = solution.lastStoneWeight(input);
	int result2=betterSolution(input);
	cout << result<<"/"<<result2;
	return 0;
}