#include "vector"
#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    int diameterOfBinaryTree(TreeNode* root);
	int lastStoneWeight(vector<int>& stones);
    int findMaxLength(vector<int>& nums);
	string stringShift(string s, vector<vector<int>>& shift);
    vector<int> productExceptSelf(vector<int>& nums) ;
    bool checkValidString(string s);
	int numIslands(vector<vector<char>>& grid);
};