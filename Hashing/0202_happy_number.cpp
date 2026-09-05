#include <unordered_set>
using namespace std;

// LeetCode 202
// Problem: Happy Number
// Difficulty: Easy
// Topic: Hashing / HashSet
// Time Complexity: O(log n) approximately
// Space Complexity: O(log n) approximately

class Solution {
public:
    bool isHappy(int n) {

        // Store numbers that we have already seen
        // to detect a cycle
        unordered_set<int> seen;

        while(n != 1) {

            // If the number is already present,
            // a cycle has been detected
            if(seen.find(n) != seen.end()) {
                return false;
            }

            seen.insert(n);

            int sum = 0;

            // Calculate the sum of squares of digits
            while(n != 0) {
                int r = n % 10;
                sum = sum + r * r;
                n = n / 10;
            }

            // Use the calculated sum as the new number
            n = sum;
        }

        // n became 1, so it is a Happy Number
        return true;
    }
};
