// LeetCode 21
// Problem: Merge Two Sorted Lists
// Difficulty: Easy
// Topic: Linked List
// Approach: Iterative Two-Pointer Merge
// Time Complexity: O(n + m)
// Space Complexity: O(1)



//LEETCODE SOLUTION


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

//         // If one of the lists is empty
//         if (list1 == NULL)
//             return list2;

//         if (list2 == NULL)
//             return list1;

//         // Choose the first node of the merged list
//         ListNode* head;
//         ListNode* current;

//         if (list1->val <= list2->val) {
//             head = list1;
//             current = head;
//             list1 = list1->next;
//         }
//         else {
//             head = list2;
//             current = head;
//             list2 = list2->next;
//         }

//         // Merge both lists
//         while (list1 != NULL && list2 != NULL) {

//             if (list1->val <= list2->val) {
//                 current->next = list1;
//                 current = current->next;
//                 list1 = list1->next;
//             }
//             else {
//                 current->next = list2;
//                 current = current->next;
//                 list2 = list2->next;
//             }
//         }

//         // Attach the remaining nodes
//         if (list1 == NULL)
//             current->next = list2;

//         if (list2 == NULL)
//             current->next = list1;

//         return head;
//     }
// };

#include <iostream>
using namespace std;

// Node structure
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    // If one list is empty
    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    // Choose the first node
    ListNode* head;
    ListNode* current;

    if (list1->val <= list2->val) {
        head = list1;
        current = head;
        list1 = list1->next;
    }
    else {
        head = list2;
        current = head;
        list2 = list2->next;
    }

    // Merge both lists
    while (list1 != NULL && list2 != NULL) {

        if (list1->val <= list2->val) {
            current->next = list1;
            current = current->next;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            current = current->next;
            list2 = list2->next;
        }
    }

    // Attach remaining nodes
    if (list1 == NULL)
        current->next = list2;

    if (list2 == NULL)
        current->next = list1;

    return head;
}

// Print linked list
void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

int main() {

    // List 1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // List 2: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Merge the two lists
    ListNode* result = mergeTwoLists(list1, list2);

    // Print result
    cout << "Merged List: ";
    printList(result);

    return 0;
}