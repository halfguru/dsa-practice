// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right,
// level by level).

#include "../Common.hpp"
#include <queue>
#include <vector>

using namespace std;

class Solution_BinaryTreeLevelOrderTraversal
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
			const int levelSize = static_cast<int>(q.size());
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
