#include <vector>
using namespace std;

// LeetCode 35
// Problem: Search Insert Position
// Difficulty: Easy
// Topic: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int s=0;
      int e=nums.size()-1;
      while(s<=e){
        int mid=s+(e-s)/2;
        if(nums[mid]==target)
        return mid;
        else if(nums[mid]>target)
        e=mid-1;
        else if(nums[mid]<target)
        //search right
        s=mid+1;
      }  
      return s;
    }
};