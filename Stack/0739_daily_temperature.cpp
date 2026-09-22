#include <vector>
#include <stack>
using namespace std;

// LeetCode 739
// Problem: Daily Temperatures
// Difficulty: Medium
// Topic: Stack
// Approach: Monotonic Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);  // Store 0 if no warmer day is found
        stack<int> st;   // Store indices of days waiting for a warmer temperature
        for(int i = 0; i < n; i++) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) { // Current temperature is warmer than previous waiting days
                ans[st.top()] = i - st.top(); // Calculate the number of days waited  
                st.pop(); // Remove the day whose answer is found
            }
            st.push(i);// Current day waits for a warmer temperature
        }
        return ans;
    }
};

//BRUTE FORCE SOLUTION



// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int> ans(n, 0);
//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 if(temperatures[j] > temperatures[i]) 
//                     ans[i] = j - i;
//                     break;
//                 }
//             }
//         }

//         return ans;
//     }
// };