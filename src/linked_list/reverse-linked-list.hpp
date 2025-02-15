// Given the head of a singly linked list, reverse the list, and return the reversed list.

#include "../Common.hpp"

// Time complexity: O(n) sizes of ListNode
// Space complexity: O(1)
class Solution_ReverseLinkedList
{
public:
	ListNode* reverseList(ListNode* head)
	{
		ListNode* prev = nullptr;
		ListNode* curr = head;
		ListNode* next = nullptr;

		while (curr)
		{
			// set next pointer to next node
			next = curr->next;
			// do the actual reversal
			curr->next = prev;
			// set previous pointer to current node
			prev = curr;
			// move current pointer to next node;
			curr = next;
		}

		return prev;
	}
};
