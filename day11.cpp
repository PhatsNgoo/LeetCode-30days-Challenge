#include "main.h"
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 0;
int Solution::diameterOfBinaryTree(TreeNode *root)
{
	treeHeight(root);
	return answer;
}

int treeHeight(TreeNode *node)
{
	if (node == NULL)
		return 0;
	int leftDiameter = treeHeight(node->left);
	int rightDiameter = treeHeight(node->right);
	answer = max(answer, leftDiameter + rightDiameter);
	return max(leftDiameter, rightDiameter) + 1;
}
int main()
{
	return 0;
}