#include "main.h"
#include <iostream>
#include <algorithm>
using namespace std;

int answer;
int Solution::diameterOfBinaryTree(TreeNode *root)
{
	answer = 0;
	if (root == NULL)
		return 0;
	treeHeight(root);
	cout << answer;
	return answer - 1;
}

int treeHeight(TreeNode *node)
{
	if (node == NULL)
		return 0;
	int leftDiameter = treeHeight(node->left);
	int rightDiameter = treeHeight(node->right);
	answer = max(answer, leftDiameter + rightDiameter + 1);
	return max(leftDiameter, rightDiameter) + 1;
}
int main()
{
	return 0;
}