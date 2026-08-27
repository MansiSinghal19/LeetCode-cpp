#include <vector>
using namespace std;

// LeetCode 167
// Problem: Two Sum II - Input Array Is Sorted
// Difficulty: Medium
// Topic: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right) {
            int sum = numbers[left] + numbers[right];

            if(sum < target)
                left++;
            else if(sum > target)
                right--;
            else
                return {left + 1, right + 1};
        }

        return {};
    }
};