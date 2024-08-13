// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as
// the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”


// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

// unlike binary search tree, its not ordered so here we need to use
// recursive stack
// time complexity: O(n) number of nodes
// space complexity: O(h) height of tree
class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (!root || root == p || root == q)
		{
			return root;
		}

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		// if p and q, it means that one of p or q was found in the left and right subtree so current node is their LCA
		if (left && right)
		{
			return root;
		}

		return left ? left : right;
	}
};
