// Given the root of a binary tree, return its maximum depth.
//
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest
// leaf node.

#include <queue>

using namespace std;

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

class Solution
{
public:
	int maxDepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}

		int depth = 0;

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			const int qSize = q.size();
			depth++;

			for (int i = 0; i < qSize; ++i)
			{
				const auto current = q.front();
				q.pop();

				if (current->left)
				{
					q.push(current->left);
				}
				if (current->right)
				{
					q.push(current->right);
				}
			}
		}

		return depth;
	}
};
