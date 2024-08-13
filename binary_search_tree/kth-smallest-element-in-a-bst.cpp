// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values
// of the nodes in the tree.

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

// in order traversal (left, root, right) will yield elements in sorted order
// time complexity: O(k) on average to visit k nodes
// space complexity: O(h) height of tree, depth of recursion stack
class Solution
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
