// BRUTE FORCE SOLUTION

#include <vector>
using namespace std;

// LeetCode 496 - Next Greater Element I
// Topic: Stack
// Approach: Brute Force
// Time Complexity: O(n * m)
// Space Complexity: O(n) - for the answer vector

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        // Process every element of nums1
        for (int i = 0; i < nums1.size(); i++)
        {
            // Default answer is -1
            int greater = -1;
            // Find nums1[i] inside nums2
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    // Search only on the right side
                    for (int k = j + 1; k < nums2.size(); k++)
                    {
                        // First greater element found
                        if (nums2[k] > nums1[i])
                        {
                            greater = nums2[k];
                            break;
                        }
                    }
                    // Element found in nums2
                    break;
                }
            }
            // Store answer
            ans.push_back(greater);
        }
        return ans;
    }
};


//OPTIMAL SOLUTION

#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

// LeetCode 496 - Next Greater Element I
// Topic: Stack
// Approach: Monotonic Stack + HashMap
// Time Complexity: O(n + m)
// Space Complexity: O(n + m)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // Stack stores elements waiting to find their next greater element
        stack<int> st;

        // Map stores: element -> next greater element
        unordered_map<int, int> mp;

        // Process every element of nums2
        for(int num : nums2) {

            // Current number is greater than the element waiting at the top
            while(!st.empty() && num > st.top()) {

                // Current number is the next greater element of st.top()
                mp[st.top()] = num;
                
                // Remove the element whose answer is found
                st.pop();
            }
            // Current number now waits for its own next greater element
            st.push(num);
        }
        vector<int> ans;

        // Find the answer for every nums1 element
        for(int num : nums1) {

            // Check if next greater element exists
            if(mp.find(num) != mp.end()) {

                // Add the next greater element
                ans.push_back(mp[num]);
            }
            else {
                // No greater element exists
                ans.push_back(-1);
            }
        }
        return ans;
    }
};