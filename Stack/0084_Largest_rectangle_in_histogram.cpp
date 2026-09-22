#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// LeetCode 84
// Problem: Largest Rectangle in Histogram
// Difficulty: Hard
// Topic: Stack
// Approach: Monotonic Increasing Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Monotonic increasing stack
        stack<int> st;
        int maxArea = 0;

        // Extra iteration to empty the stack
        for(int i = 0; i <= n; i++) {
            int currentHeight;

            // Use 0 as sentinel
            if(i == n)
                currentHeight = 0;
            else
                currentHeight = heights[i];

            // Smaller height → calculate previous bars
            while(!st.empty() && currentHeight < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();
                int width;

                // No smaller bar on left
                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                // Calculate area
                int area = height * width;
                maxArea = max(maxArea, area);
            }
            // Don't push fake index n
            if(i < n)
                st.push(i);
        }
        return maxArea;
    }
};