#include <vector>
using namespace std;

// LeetCode 1929
// Problem: Concatenation of Array
// Difficulty: Easy
// Topic: Array
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(2 * n);

        for(int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
};