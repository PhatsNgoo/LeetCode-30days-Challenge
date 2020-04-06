#include "main.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>

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
int main()
{
}