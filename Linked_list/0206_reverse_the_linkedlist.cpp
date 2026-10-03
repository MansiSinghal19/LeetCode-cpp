// LeetCode 206
// Problem: Reverse Linked List
// Difficulty: Easy
// Topic: Linked List
// Approach: Iterative Pointer Reversal
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;

        while (current != NULL) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};