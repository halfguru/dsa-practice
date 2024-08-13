// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes
// you can see ordered from top to bottom.

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

// time complexity: O(n) number of nodes
// space complexity: O(n) storing result in queue
class Solution
{
public:
	vector<int> rightSideView(TreeNode* root)
	{
		vector<int> results;
		if (!root)
		{
			return results;
		}

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			const int qSize = q.size();

			for (int i = 0; i < qSize; ++i)
			{
				const auto current = q.front();
				q.pop();

				// if we reach the last element of queue, it means its the rightmost element
				// in the level
				if (i == qSize - 1)
				{
					results.push_back(current->val);
				}
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

		return results;
	}
};
