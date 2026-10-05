// LeetCode 143 - Reorder List
// Topic: Linked List
// Approach: Slow/Fast Pointer + Reverse + Merge
// Time Complexity: O(n)
// Space Complexity: O(1)


// //LEETCODE SOLUTION
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//       ListNode* slow = head;
//       ListNode* fast = head; 
//       while(fast!=NULL && fast->next!=NULL){
//         slow = slow->next;
//         fast = fast->next->next;
//       } 

//       //middle + split part 
//       ListNode* current = slow->next;
//       slow->next =NULL;

//       //reverse code 
//       ListNode* prev = NULL;
//       while(current!= NULL)
//       {
//       ListNode* next = current->next;
//       current->next = prev;
//       prev = current;
//       current = next;
//       }
//       //merge k liye 
//       ListNode* first = head ;
//       ListNode* second = prev;

//       while(second != NULL)
//       {
//       //Merge karte waqt pehle next nodes save karne padenge,
//       //otherwise pointers lose ho sakte hain
//       ListNode* firstNext = first->next;
//       ListNode* secondNext = second->next;
//       //while merging nodes
//       first->next = second;
//       second->next = firstNext;
//       first = firstNext;
//       second = secondNext;
//       }
//     }
// };


//FULL SOLUTION
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    void reorderList(ListNode* head) {

        // Edge case
        if (head == NULL || head->next == NULL)
            return;

        // 1. Find the middle using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split the list into two halves
        ListNode* current = slow->next;
        slow->next = NULL;

        // 3. Reverse the second half
        ListNode* prev = NULL;

        while (current != NULL) {
            ListNode* next = current->next;

            current->next = prev;
            prev = current;
            current = next;
        }

        // 4. Merge both halves alternately
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {

            // Save next nodes
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            // Connect nodes alternately
            first->next = second;
            second->next = firstNext;

            // Move pointers
            first = firstNext;
            second = secondNext;
        }
    }
};

// Function to print linked list
void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

int main() {

    // Creating linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List:" << endl;
    printList(head);

    // Create Solution object
    Solution obj;

    // Reorder the list
    obj.reorderList(head);

    cout << "Reordered List:" << endl;
    printList(head);

    return 0;
}