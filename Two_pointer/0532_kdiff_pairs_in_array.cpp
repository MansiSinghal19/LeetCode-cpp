#include <vector>
#include <algorithm>
using namespace std;
// LeetCode 532
// Problem: K-diff Pairs in an Array
// Difficulty: Medium
// Topic: Sorting + Two Pointers
// Time Complexity: O(n log n)
// Space Complexity: O(1)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;
        int count = 0;
        while (j < nums.size()) {
            if (i == j) {
                j++;
                continue;
            }
            int diff = nums[j] - nums[i];
            if (diff == k) {
                count++;
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                    j++;
                }
                i++;
                j++;
            }
            else if (diff > k) {
                i++;
            }
            else {
                j++;
            }
        }
        return count;
    }
};