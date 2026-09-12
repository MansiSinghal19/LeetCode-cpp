#include <vector>
#include <unordered_map>
using namespace std;

// LeetCode 219
// Problem: Contains Duplicate II
// Difficulty: Easy
// Topic: Hashing / HashMap
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            // Check if the number already exists in the map
            if(mp.find(nums[i]) != mp.end()) {
                // Check if the previous occurrence is within k distance
                if(i - mp[nums[i]] <= k) {
                    return true;
                }
            }
            // Store the latest index of the number
            mp[nums[i]] = i;
        }
        return false;
    }
};
