// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder
// is the inorder traversal of the same tree, construct and return the binary tree.

#include "../Common.hpp"
#include <unordered_map>
#include <vector>

using namespace std;

// preorder: RO->L->R
// inorder: L->R->RO
// 1. find root with 1st element of preorder
// 2. find root in inorder traversal that splits the initial left and right subtrees
// 3. Recursively build subtrees using left anr right parts of inorder array.
// Preorder will be used to provide the root nodes for these subtrees
// time complexity: O(n) number of nodes
// space complexity: O(n) recursion stack
class Solution_ConstructBinaryTreeFromPreorderAndInorderTraversal
{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		unordered_map<int, int> inOrderIndexMap;
		// create map for quick lookup of inorder indices
		for (int i = 0; i < inorder.size(); ++i)
		{
			inOrderIndexMap[inorder[i]] = i;
		}

		return buildTreeHelper(preorder, inorder, 0, 0, inorder.size() - 1, inOrderIndexMap);
	}

	TreeNode* buildTreeHelper(
		const vector<int>& preorder,
		const vector<int>& inorder,
		int preorderStart,
		int inorderStart,
		int inorderEnd,
		const unordered_map<int, int>& inOrderIndexMap)
	{
		if (preorderStart >= preorder.size() || inorderStart > inorderEnd)
		{
			return nullptr;
		}

		// 1. find root
		int rootVal = preorder[preorderStart];
		TreeNode* root = new TreeNode(rootVal);

		// 2. index of root in inorder array
		int inorderIndex = inOrderIndexMap.at(rootVal);

		// partition inorder array in left and right subtree
		// number of nodes in left subtree is simply the number of nodes
		// before the root index
		const int leftSize = inorderIndex - inorderStart;

		// 3. recursively build left and right subtrees
		root->left
			= buildTreeHelper(preorder, inorder, preorderStart + 1, inorderStart, inorderIndex - 1, inOrderIndexMap);
		root->right = buildTreeHelper(
			preorder, inorder, preorderStart + 1 + leftSize, inorderIndex + 1, inorderEnd, inOrderIndexMap);

		return root;
	}
};
