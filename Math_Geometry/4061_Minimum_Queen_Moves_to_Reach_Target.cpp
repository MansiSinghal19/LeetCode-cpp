// LeetCode 4061
// Problem: Minimum Queen Moves to Reach Target
// Difficulty: Easy
// Topic: Math & Geometry
// Approach: Coordinate / Chessboard Logic
// Time Complexity: O(1)
// Space Complexity: O(1)

#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {

        int sr = source[0];
        int sc = source[1];

        int tr = target[0];
        int tc = target[1];

        // Source and target are already the same
        if (sr == tr && sc == tc)
            return 0;

        // Same row or same column
        if (sr == tr || sc == tc)
            return 1;

        // Same diagonal
        if (abs(sr - tr) == abs(sc - tc))
            return 1;

        // Otherwise, queen needs two moves
        return 2;
    }
};