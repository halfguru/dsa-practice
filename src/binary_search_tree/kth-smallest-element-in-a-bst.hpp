// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values
// of the nodes in the tree.

#include "../Common.hpp"

// in order traversal (left, root, right) will yield elements in sorted order
// time complexity: O(k) on average to visit k nodes
// space complexity: O(h) height of tree, depth of recursion stack
class Solution_kthSmallestElementInABst
{
public:
	int kthSmallest(TreeNode* root, int k)
	{
		int count = 0; // number of nodes visited
		int result = -1;

		inOrderTraversal(root, k, count, result);

		return result;
	}


	void inOrderTraversal(TreeNode* node, int k, int& count, int& result)
	{
		if (!node)
		{
			return;
		}

		// traverse left subtree
		inOrderTraversal(node->left, k, count, result);

		// visit current node
		count++;
		if (count == k)
		{
			result = node->val;
			return;
		}

		inOrderTraversal(node->right, k, count, result);
	}
};
