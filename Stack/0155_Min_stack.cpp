#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

// LeetCode 155
// Problem: Min Stack
// Difficulty: Medium
// Topic: Stack
// Approach: Stack of Pairs
// Time Complexity: O(1) for every operation
// Space Complexity: O(n)

class MinStack {
public:

    // first  -> actual value
    // second -> minimum value so far
    stack<pair<int, int>> s;

    MinStack() {   
    }
    void push(int val) {
        // If stack is empty,
        // current value is the minimum
        if(s.empty()) {
            s.push({val, val});
        }
        else {
            // Find the minimum between
            // current value and previous minimum
            int minVal = min(val, s.top().second);
            // Store value and current minimum
            s.push({val, minVal});
        }
    }
    void pop() {
        s.pop();
    }
    int top() {
        return s.top().first;
    }
    int getMin() {
        return s.top().second;
    }
};