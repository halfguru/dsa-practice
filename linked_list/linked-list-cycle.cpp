// Given head, the head of a linked list, determine if the linked list has a cycle in it.
//
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously
// following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is
// connected to. Note that pos is not passed as a parameter.
//
// Return true if there is a cycle in the linked list. Otherwise, return false.

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(nullptr) {}
};

// Time complexity: O(n)
// Space complexity: O(1)
class Solution
{
public:
	bool hasCycle(ListNode* head)
	{
		ListNode* fast = head;
		ListNode* slow = head;

		// check for nullptr to avoid accessing member of a nullptr, causing a runtime error
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;

			// if one pointer manages to catch up to the other
			if (fast == slow)
			{
				return true;
			}
		}

		return false;
	}
};
