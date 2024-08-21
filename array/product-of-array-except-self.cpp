// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements
// of nums except nums[i].
//
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//
// You must write an algorithm that runs in O(n) time and without using the division operation.

#include <vector>

using namespace std;

// Pass 1: left products, products of all elements at the left of nums[i]
// Pass 2: right products, products of all elements at the right of nums[i]
// Multiply these right products with the corresponding left products

class Solution
{
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		const int n = nums.size();
		vector<int> answer(n, 1);

		// left products
		int leftProduct = 1;
		for (int i = 0; i < n; ++i)
		{
			answer[i] = leftProduct;
			leftProduct *= nums[i];
		}

		int rightProduct = 1;
		for (int i = n - 1; i >= 0; --i)
		{
			answer[i] = rightProduct;
			rightProduct *= nums[i];
		}

		return answer;
	}
};
