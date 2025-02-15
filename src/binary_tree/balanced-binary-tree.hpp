// Given a binary tree, determine if it is height-balanced
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by
// more than one.

#include "../Common.hpp"
#include <algorithm>

// Time complexity: O(n) with n being number of nodes because of DFS
// Space complexity: O(h) height of tree because of recursion stack
class Solution_BalancedBinaryTree
{
public:
	bool isBalanced(TreeNode* root) { return dfsHeight(root) != -1; }

	int dfsHeight(TreeNode* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		const int leftHeight = dfsHeight(node->left);
		if (leftHeight == -1)
		{
			return -1;
		}

		const int rightHeight = dfsHeight(node->right);
		if (rightHeight == -1)
		{
			return -1;
		}

		if (std::abs(leftHeight - rightHeight) > 1)
		{
			return -1;
		}

		// returns the height of the subtree which is the max between left and right + the current node
		return std::max(leftHeight, rightHeight) + 1;
	}
};
