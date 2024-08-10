/*
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists into one sorted list. The list should be made by splicing
 * together the nodes of the first two lists. Return the head of the merged
 * linked list.
 */

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};

// Solution is to create a dummy node and iterate with two pointers
// Time complexity: O(n+m) where n is number of nodes in list1 and m number of
// nodes in list2. This is because we traverse each node once.
// Space complexity: O(1) nothing created except pointers which are constant in
// size
class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode dummy;
		ListNode* tail = &dummy;

		while (list1 != nullptr && list2 != nullptr)
		{
			if (list1->val < list2->val)
			{
				tail->next = list1;
				list1 = list1->next;
			}
			else
			{
				tail->next = list2;
				list2 = list2->next;
			}
			tail = tail->next;
		}
		if (list1 != nullptr)
		{
			tail->next = list1;
		}
		else
		{
			tail->next = list2;
		}

		return dummy.next;
	}
};
