// Given the head of a singly linked list, return the middle node of the linked list.
//
// If there are two middle nodes, return the second middle node.

#include "../Common.hpp"

// Time complexity: O(n) traverse the number of nodes
// Space complexity: O(1) pointer don't depend on size of nodes
class Solution_MiddleOfTheLinkedList
{
public:
	ListNode* middleNode(ListNode* head)
	{
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow;
	}
};
