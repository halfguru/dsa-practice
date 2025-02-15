// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//
// Merge all the linked-lists into one sorted linked-list and return it.

#include "../Common.hpp"
#include <queue>
#include <vector>

using namespace std;

// use min heap to extract smallest element from heap
// time complextiy: O(nlogk) extracting node is O(logk) for n nodes
// space complexity: O(k) for k elements in priority_queue
class Solution_MergeKSortedLists
{
public:
	struct compare
	{
		bool operator()(ListNode* a, ListNode* b)
		{
			return a->val > b->val; // min heap: smallest element of top
		}
	};

	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
		for (ListNode* list: lists)
		{
			if (list)
			{
				minHeap.push(list);
			}
		}


		ListNode* dummy = new ListNode(0);
		ListNode* current = dummy;

		while (!minHeap.empty())
		{
			ListNode* smallest = minHeap.top();
			minHeap.pop();

			// add smallest node the merged list
			current->next = smallest;
			current = current->next;

			// if there are more nodes in list, add the next node to the heap
			if (smallest->next)
			{
				minHeap.push(smallest->next);
			}
		}

		return dummy->next;
	}
};
