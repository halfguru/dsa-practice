// Given an array nums of size n, return the majority element.
//
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element
// always exists in the array.

#include <unordered_map>
#include <vector>

using namespace std;

// time complexity: O(n)
// space complexity: O(n)
class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		int n = nums.size();
		unordered_map<int, int> m;

		// store the count of occurence of each element
		for (int i = 0; i < n; ++i)
		{
			m[nums[i]]++;
		}

		n = n / 2;
		for (const auto& x: m)
		{
			// if count is more than n/2 then return that element
			if (x.second > n)
			{
				return x.first;
			}
		}

		return 0;
	}
};
