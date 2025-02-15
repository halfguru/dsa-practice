// A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any
// connected graph without simple cycles is a tree.
//
// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates
// that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as
// the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those
// with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
//
// Return a list of all MHTs' root labels. You can return the answer in any order.
//
// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

#include <queue>
#include <vector>

using namespace std;

// we start with outermost nodes (leaves) that only have 1 edge
// we know leaves cannot be roots
// trim leaves iteratively by remove leaves layer by leave to reduce problem size
// continue until 1 or 2 nodes are left
// Time complexity: O(n) n being number of nodes
// Space complexity: O(n) n being number of nodes
class Solution_MinimumHeightTrees
{
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
	{
		if (n == 1)
		{
			return {0};
		}

		// build adjacency list
		vector<vector<int>> adj(n); // list fo neighbors for given node
		vector<int> degree(n, 0);	// number of edges for given node

		// for each edge, add node
		for (const auto& edge: edges)
		{
			// 2 nodes connected by an edge in the tree
			// add each other to adjacency list
			const int u = edge[0];
			const int v = edge[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
			degree[u]++;
			degree[v]++;
		}

		std::queue<int> leaves;
		for (int i = 0; i < n; ++i)
		{
			if (degree[i] == 1)
			{
				leaves.push(i);
			}
		}

		// trim leaves until we reach core
		int remainingNodes = n;

		while (remainingNodes > 2)
		{
			// loop continues as long as there are more than 2 nodes remaining
			const int leavesCount = static_cast<int>(leaves.size());
			remainingNodes -= leavesCount;

			// process each leaf
			for (int i = 0; i < leavesCount; ++i)
			{
				const int leaf = leaves.front();
				leaves.pop();
				// for each, iterate over its neighbors using the adjacency list
				for (const int& neighbor: adj[leaf])
				{
					// decrease number of edge by trimming leaf
					degree[neighbor]--;
					// that neighbor becomes a leaf in next iteration
					// neighbor is added to queue of leaves to be processed for trimming
					if (degree[neighbor] == 1)
					{
						leaves.push(neighbor);
					}
				}
			}
		}

		// remaining nodes are centroids of the tree
		vector<int> result;
		while (!leaves.empty())
		{
			result.push_back(leaves.front());
			leaves.pop();
		}

		return result;
	}
};
