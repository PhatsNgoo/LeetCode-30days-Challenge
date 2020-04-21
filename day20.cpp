#include "main.h"
#include <iostream>

using namespace std;

TreeNode *Solution::bstFromPreorder(vector<int> &preorder)
{
	TreeNode *root = new TreeNode(preorder[0]);
	root->val = preorder[0];
	for (int i = 0; i < preorder.size(); i++)
	{
		TreeNode *ptr = root;
		while (ptr->left != NULL && ptr->right != NULL)
		{
			if (preorder[i] < ptr->val)
			{
				if (ptr->left == NULL)
				{
					TreeNode *tmp;
					ptr->left = tmp;
					tmp->val = preorder[i];
				}
				else
				{
					ptr = ptr->left;
				}
			}
			else
			{
				if (ptr->right == NULL)
				{
					TreeNode *tmp;
					ptr->right = tmp;
					tmp->val = preorder[i];
				}
				else
				{
					ptr = ptr->right;
				}
			}
		}
	}
	return root;
}

//Better solution O(N)
int i = 0;
TreeNode *bstFromPreorder(vector<int> &A, int bound = INT_MAX)
{
	if (i == A.size() || A[i] > bound)
		return NULL;
	TreeNode *root = new TreeNode(A[i++]);
	root->left = bstFromPreorder(A, root->val);
	root->right = bstFromPreorder(A, bound);
	return root;
}
int main()
{
	return 0;
}