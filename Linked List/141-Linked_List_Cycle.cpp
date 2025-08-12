/*
LeetCode #141: Linked List Cycle
Link: https://leetcode.com/problems/linked-list-cycle/
Difficulty: Easy
Tags: Linked List, Two Pointers

Approach:  
We use Floyd's Cycle Detection Algorithm (also known as the Tortoise and Hare algorithm).  
- Maintain two pointers: `slow` moves one step at a time, `fast` moves two steps at a time.  
- If there is no cycle, `fast` will eventually reach `nullptr`.  
- If there is a cycle, both pointers will eventually meet inside the cycle.  

Time Complexity: O(n) — Each pointer traverses the list at most once.  
Space Complexity: O(1) — Only two pointers are used, regardless of list size.
*/

#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
				//fast and slow pointer
        ListNode* slow = head;  //will move 1 steps at a time
        ListNode* fast = head;   //will move 2 steps at a time

        //if there is no cycle - fast will eventually end up at nullptr
        //if there is a cycle -  both fast and slow will enter the cycle and eventually meet.
        while(fast!= nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;    //moves two steps at a time
            slow = slow->next;          //moves one step at a time
            if(fast == slow)
            {
                //fast and slow meets - cycle exists
                return true;
            }
        }

        //fast reached nullptr - no cycle exists
        return false;
    }
};

// ### OPTIONAL TEST - FOR LOCAL TESTING
// int main() {
//     // Create a cycle list: 3 -> 2 -> 0 -> -4 -> points back to node 2
//     ListNode* head = new ListNode(3);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(0);
//     head->next->next->next = new ListNode(-4);
//     head->next->next->next->next = head->next; // cycle here

//     Solution sol;
//     cout << sol.hasCycle(head) << endl; // Expected output: 1 (true)
//     return 0;
// }
