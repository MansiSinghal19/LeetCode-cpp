#include <string>
#include <unordered_map>
using namespace std;

// LeetCode 383
// Problem: Ransom Note
// Difficulty: Easy
// Topic: Hashing / HashMap
// Time Complexity: O(n + m)
// Space Complexity: O(k)

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mp;

        // Count available characters in magazine
        for (char x : magazine)
        {
            mp[x]++;
        }

        // Use characters required by ransomNote
        for (char x : ransomNote)
        {
            mp[x]--;
        }

        // Check if any character was unavailable
        for (auto x : mp)
        {
            if (x.second < 0)
            {
                return false;
            }
        }

        return true;
    }
};
