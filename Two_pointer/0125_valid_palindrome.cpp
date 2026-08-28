#include <string>
#include <cctype>
using namespace std;

// LeetCode 125
// Problem: Valid Palindrome
// Difficulty: Easy
// Topic: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            // Skip non-alphanumeric characters from left
            if(!isalnum(s[left])) {
                left++;
                continue;
            }
            // Skip non-alphanumeric characters from right
            if(!isalnum(s[right])) {
                right--;
                continue;
            }
            // Compare characters ignoring case
            if(tolower(s[left]) != tolower(s[right]))
                return false;
            // Move both pointers
            left++;
            right--;
        }
        return true;
    }
};