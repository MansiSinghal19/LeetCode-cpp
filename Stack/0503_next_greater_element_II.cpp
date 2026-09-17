#include <vector>
#include <stack>
using namespace std;

// LeetCode 503 - Next Greater Element II
// Topic: Stack
// Approach: Monotonic Stack + Circular Array
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        // Initially, answer for every element is -1
        vector<int> ans(n, -1);

        // Stack stores indices of elements
        // whose next greater element is not found yet
        stack<int> st;

        // Traverse the array twice
        // to simulate a circular array
        for(int i = 0; i < 2 * n; i++) {

            // Convert the virtual index into
            // an actual array index
            int idx = i % n;

            // Current element is greater than
            // the element waiting at the top
            while(!st.empty() && nums[idx] > nums[st.top()]) {

                // Current element is the next greater
                // element for the index at the top
                ans[st.top()] = nums[idx];

                // Remove that index because
                // its answer has been found
                st.pop();
            }

            // Push indices only during the first traversal
            if(i < n) {
                st.push(idx);
            }
        }

        return ans;
    }
};