// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
//
// A valid BST is defined as follows:
//
// The left
// subtree
//  of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

#include <limits.h>

// time complexity: O(n) number of nodes
// space complexity: O(h) height of tree because of recursion stack
class Solution
{
public:
	bool isValidBST(TreeNode* root) { return validate(root, LONG_MIN, LONG_MAX); }

	bool validate(TreeNode* node, long long minVal, long long maxVal)
	{
		if (!node)
		{
			return true;
		}

		if (node->val <= minVal || node->val >= maxVal)
		{
			return false;
		}

		return validate(node->left, minVal, node->val) && validate(node->right, node->val, maxVal);
	}
};
