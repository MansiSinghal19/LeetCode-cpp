#include <vector>
using namespace std;

// LeetCode 121
// Problem: Best Time to Buy and Sell Stock
// Difficulty: Easy
// Topic: Array, Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {

            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            else {
                int profit = prices[i] - minPrice;

                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }

        return maxProfit;
    }
};