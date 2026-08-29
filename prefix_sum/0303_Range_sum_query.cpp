#include <vector>
using namespace std;

// LeetCode 303
// Problem: Range Sum Query - Immutable
// Difficulty: Easy
// Topic: Prefix Sum
// Time Complexity: O(n) for construction, O(1) for sumRange
// Space Complexity: O(n)

class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {
        int n = nums.size();

        prefix.resize(n);

        prefix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if(left == 0) {
            return prefix[right];
        }
        else {
            return prefix[right] - prefix[left - 1];
        }
    }
};