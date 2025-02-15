// Given the root of a binary tree, invert the tree, and return its root.

#include "../Common.hpp"

// Time complexity: O(n)
// Space complexity: O(h) recursive stack space, height of tree h
class Solution_InvertBinaryTree
{
public:
	TreeNode* invertTree(TreeNode* root)
	{
		if (root)
		{
			TreeNode* temp = root->left;
			root->left = root->right;
			root->right = temp;
			invertTree(root->left);
			invertTree(root->right);
		}
		return root;
	}
};
