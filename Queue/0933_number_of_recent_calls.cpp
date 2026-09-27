// LeetCode 933
// Problem: Number of Recent Calls
// Difficulty: Easy
// Topic: Queue + Sliding Window
// Approach: Queue Simulation
// Time Complexity: O(n) amortized
// Space Complexity: O(n)

#include <queue>
using namespace std;

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() { //constructor
    }

    int ping(int t) { //called whenever new request happen
        q.push(t);    //add current timestamp back to the queue

        int low = t - 3000; //lower limit of valid time window

        while (!q.empty() && q.front() < low)
            q.pop();

        // Return number of requests in the range [t - 3000, t]
        return q.size();
    }
};