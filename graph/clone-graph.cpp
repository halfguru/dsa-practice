// Given a reference of a node in a connected undirected graph.
//
// Return a deep copy (clone) of the graph.
//
// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
//
// class Node {
//     public int val;
//     public List<Node> neighbors;
// }

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node
{
public:
	int val;
	vector<Node*> neighbors;
	Node()
	{
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val)
	{
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors)
	{
		val = _val;
		neighbors = _neighbors;
	}
};

// Time complexity: O(V+E) where V and E are vertices and edges
// Space complexity: O(V) number of vertices for hash map and BFS queue
class Solution
{
public:
	Node* cloneGraph(Node* node)
	{
		if (!node)
		{
			return nullptr;
		}

		// hash map to store mapping from original node to clone
		std::unordered_map<Node*, Node*> clonedNodes;

		std::queue<Node*> q;
		q.push(node);
		clonedNodes[node] = new Node(node->val);


		// BFS traversal
		while (!q.empty())
		{
			Node* current = q.front();
			q.pop();

			// iterate through all neighbors
			for (Node* neighbor: current->neighbors)
			{
				// not cloned yet
				if (clonedNodes.find(neighbor) == clonedNodes.end())
				{
					clonedNodes[neighbor] = new Node(neighbor->val);
					q.push(neighbor);
				}

				// link the clone of the current node to the clone of the neighbor
				clonedNodes[current]->neighbors.push_back(clonedNodes[neighbor]);
			}
		}

		return clonedNodes[node];
	}
};
