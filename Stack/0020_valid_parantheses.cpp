#include <string>
#include <stack>
using namespace std;

// LeetCode 20
// Problem: Valid Parentheses
// Difficulty: Easy
// Topic: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isValid(string s) {

        // Create a stack to store opening brackets
        stack<char> st;

        // Traverse the string character by character
        for(char ch : s) {

            // If the character is an opening bracket, push it into the stack
            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            // Otherwise, the character is a closing bracket
            else {

                // If stack is empty, there is no opening bracket, available to match the closing bracket
                if(st.empty()) {
                    return false;
                }

                // Check if ')' matches '('
                if(ch == ')' && st.top() == '(') {
                    st.pop();
                }

                // Check if ']' matches '['
                else if(ch == ']' && st.top() == '[') {
                    st.pop();
                }

                // Check if '}' matches '{'
                else if(ch == '}' && st.top() == '{') {
                    st.pop();
                }

                // If brackets do not match
                else {
                    return false;
                }
            }
        }

        // If stack is empty, all brackets were matched
        return st.empty();
    }
};
