#include <vector>
using namespace std;

// LeetCode 643
// Problem: Maximum Average Subarray I
// Difficulty: Easy
// Topic: Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        // First window
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double maxAverage = (double)sum / k;

        // Sliding Window
        for(int i = 0; i < n - k; i++) {
            sum = sum - nums[i] + nums[i + k];
            double currentAverage = (double)sum / k;
            if(currentAverage > maxAverage)
                maxAverage = currentAverage;
        }
        return maxAverage;
    }
};
