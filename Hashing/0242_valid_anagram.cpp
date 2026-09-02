#include <string>
#include <unordered_map>
using namespace std;

// LeetCode 242
// Problem: Valid Anagram
// Difficulty: Easy
// Topic: Hashing / HashMap
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
bool isAnagram(string s, string t) {
if(s.length() != t.length()) {
return false;
}
    unordered_map<char, int> mp;

    // Count characters in s
    for(char x : s) {
        mp[x]++;
    }
    // Subtract characters using t
    for(char x : t) {
        mp[x]--;
    }

    // Check if all frequencies are zero
    for(auto x : mp) {
        if(x.second != 0) {
            return false;
        }
    }
    return true;
}
};
