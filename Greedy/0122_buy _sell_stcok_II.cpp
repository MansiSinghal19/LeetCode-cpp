#include <vector>
using namespace std;

// LeetCode 122
// Problem: Best Time to Buy and Sell Stock II
// Difficulty: Medium
// Topic: Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();

        for(int i = 1; i < n; i++) {
            if(prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};