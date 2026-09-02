#include <vector>
#include <unordered_map>
using namespace std;

// LeetCode 217
// Problem: Contains Duplicate
// Difficulty: Easy
// Topic: Hashing / HashMap
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int x : nums)
        {
            mp[x]++;
            if (mp[x] > 1)
            {
                return true;
            }
        }
        return false;
    }
};
