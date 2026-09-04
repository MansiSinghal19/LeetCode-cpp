#include <vector>
#include <unordered_set>
using namespace std;

// LeetCode 349
// Problem: Intersection of Two Arrays
// Difficulty: Easy
// Topic: Hashing / HashSet
// Time Complexity: O(n + m)
// Space Complexity: O(n + m)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        // Store unique elements of nums1
        for(int x : nums1) {
            st.insert(x);
        }
        // Store common elements
        unordered_set<int> ans;

        for(int x : nums2) {
            if(st.find(x) != st.end()) {
                ans.insert(x);
            }
        }

        // Convert set to vector
        vector<int> result(ans.begin(), ans.end());

        return result;
    }
};