// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array
// prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take
// course ai.
//
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

#include <vector>

using namespace std;

// example of detecting cycles in directed graph
// courses are nodes with a relationship to prerequesite [a,b], directed edge from b to a
// time complexity: O(V+E) traverse each vertice and edge
// space complexity: O(V+E) same thing
class Solution
{
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		// 3 states
		// 0: unvisited
		// -1: visiting (currently in recursion stack)
		// 1: visited (fully explored, no cycle found)
		vector<int> visited(numCourses, 0);
		vector<vector<int>> graph(numCourses);

		// Build the graph
		for (const auto& pair: prerequisites)
		{
			// add an edge from pair[1] to pair[0]
			// b is a prerequesite to a
			graph[pair[1]].push_back(pair[0]);
		}

		// Perform DFS for each course by checking for cycles
		for (int i = 0; i < numCourses; ++i)
		{
			if (hasCycle(i, graph, visited))
			{
				// cycle detected
				return false;
			}
		}

		return true;
	}


	bool hasCycle(int course, const vector<vector<int>>& graph, vector<int>& visited)
	{
		// cycle detected, node is revisted
		if (visited[course] == -1)
		{
			return true;
		}

		// node has already been checked, no cycle here
		if (visited[course] == 1)
		{
			return false;
		}

		// current node is visiting
		visited[course] = -1;

		// visit all neighbors (prerequesites)
		for (const int neighbor: graph[course])
		{
			if (hasCycle(neighbor, graph, visited))
			{
				return true;
			}
		}

		visited[course] = 1;

		return false;
	}
};
