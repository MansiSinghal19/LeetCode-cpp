// LeetCode 994
// Problem: Rotting Oranges
// Difficulty: Medium
// Topic: BFS + Queue
// Approach: Multi-Source BFS
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;

        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        int minutes = 0;

        // Store all initially rotten oranges
        // and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Up, Down, Left, Right
        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        // Multi-Source BFS
        while (!q.empty() && fresh > 0) {

            int size = q.size();

            // Process all oranges at current minute
            for (int i = 0; i < size; i++) {

                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                // Check all 4 directions
                for (int d = 0; d < 4; d++) {

                    int newRow = row + directions[d][0];
                    int newCol = col + directions[d][1];

                    // Check valid position and fresh orange
                    if (newRow >= 0 && newRow < n &&
                        newCol >= 0 && newCol < m &&
                        grid[newRow][newCol] == 1) {

                        // Make fresh orange rotten
                        grid[newRow][newCol] = 2;

                        // Add newly rotten orange to queue
                        q.push({newRow, newCol});

                        // One fresh orange became rotten
                        fresh--;
                    }
                }
            }

            // One BFS level = one minute
            minutes++;
        }

        // All fresh oranges became rotten
        if (fresh == 0) {
            return minutes;
        }

        // Some fresh oranges cannot be reached
        return -1;
    }
};