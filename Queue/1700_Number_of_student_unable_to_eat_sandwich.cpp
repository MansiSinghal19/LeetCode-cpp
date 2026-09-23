#include <queue>
#include <vector>
using namespace std;

// LeetCode 1700
// Problem: Number of Students Unable to Eat Lunch
// Difficulty: Easy
// Topic: Queue
// Approach: Queue Simulation
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        // Put all students into the queue
        for(int i = 0; i < students.size(); i++) {
            q.push(students[i]);
        }
        int i = 0;
        int rotations = 0;

        while(!q.empty()) {
            // Student wants the current sandwich
            if(q.front() == sandwiches[i]) {
                q.pop();
                i++;
                rotations = 0;
            }
            // Student does not want the current sandwich
            else {
                int student = q.front();

                q.pop();
                q.push(student);
                rotations++;

                // Nobody in the queue wants this sandwich
                if(rotations == q.size()) {
                    break;
                }
            }
        }
        return q.size();
    }
};