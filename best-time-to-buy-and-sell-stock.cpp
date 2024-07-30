/* You are given an array prices where prices[i] is the price of a given stock
 * on the ith day. You want to maximize your profit by choosing a single day to
 * buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 */
#include <algorithm>

using namespace std;

/* Time complexity: O(n)
 * Spac complexity: O(1)
 */
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) {
      prices[0];
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (size_t i = 1; i < prices.size(); i++) {
      const int currentPrice = prices[i];
      const int currentProfit = currentPrice - minPrice;

      maxProfit = std::max(maxProfit, currentProfit);
      minPrice = std::min(minPrice, currentPrice);
    }

    return maxProfit;
  }
};
