// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right,
// level by level).

#include <queue>
#include <vector>


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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> result;
		if (!root)
		{
			return result;
		}

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			const int levelSize = q.size();
			vector<int> currentLevel;

			for (int i = 0; i < levelSize; ++i)
			{
				const auto current = q.front();
				q.pop();
				currentLevel.push_back(current->val);

				// add left child to queue if it exists
				if (current->left)
				{
					q.push(current->left);
				}

				if (current->right)
				{
					q.push(current->right);
				}
			}

			result.push_back(currentLevel);
		}

		return result;
	}
};
