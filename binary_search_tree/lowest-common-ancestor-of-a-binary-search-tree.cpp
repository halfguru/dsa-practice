// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as
// the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

#include <algorithm>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

// Time complexity: O(n)
// Space complexity: O(h) height of tree
class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		const int large = std::max(p->val, q->val);
		const int small = std::min(p->val, q->val);

		while (root)
		{
			if (root->val > large)
			{
				root = root->left;
			}
			else if (root->val < small)
			{
				root = root->right;
			}
			else
			{
				return root;
			}
		}
		return nullptr;
	}
};
