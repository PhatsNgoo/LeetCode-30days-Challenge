#include "vector"
#include <iostream>

using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
private:

	/* data */
public:
	int singleNumber(vector<int> &nums);
	int maxSubArray(vector<int> &nums);
	void moveZeroes(vector<int> &nums);
	int maxProfit(vector<int> &prices);
	vector<vector<string>> groupAnagrams(vector<string> &strs);
	int countElements(vector<int> &arr);
	ListNode *middleNode(ListNode *head);
    bool backspaceCompare(string S, string T);
};