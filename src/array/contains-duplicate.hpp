// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every
// element is distinct.

#include <unordered_set>
#include <vector>

using namespace std;

// time complexity: O(n) lookup and inset on set is O(1)
// space complexity: O(n)
class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		unordered_set<int> m;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (m.find(nums[i]) != m.end())
			{
				return true;
			}
			m.insert(nums[i]);
		}

		return false;
	}
};
