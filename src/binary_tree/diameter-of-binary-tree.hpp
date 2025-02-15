// Given the root of a binary tree, return the length of the diameter of the tree.
//
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may
// not pass through the root.
//
// The length of a path between two nodes is represented by the number of edges between them.

#include "../Common.hpp"
#include <algorithm>

using namespace std;

// time complexity: O(n) number of nodes
// space compleixity: O(h) height of tree
class Solution_DiameterOfBinaryTree
{
public:
	int diameterOfBinaryTree(TreeNode* root)
	{
		int diameter = 0;
		height(root, diameter);
		return diameter;
	}

	int height(TreeNode* node, int& diameter)
	{
		if (!node)
		{
			return 0;
		}

		const int leftHeight = height(node->left, diameter);
		const int rightHeight = height(node->right, diameter);

		// potential diameter at current node is sum of height of left and right subtree
		// diameter is LONGEST path possible between 2 nodes
		diameter = max(diameter, leftHeight + rightHeight);

		// height of node
		return max(leftHeight, rightHeight) + 1;
	}
};
