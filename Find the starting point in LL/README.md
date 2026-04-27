🔁 Find Starting Point of Loop in Linked List

This project demonstrates how to detect a cycle in a singly linked list and find the exact node where the loop begins using Floyd’s Cycle Detection Algorithm (Tortoise and Hare).

🚀 Approach Overview

This solution extends the classic cycle detection technique:

1. Detect Cycle
Use two pointers:
slow → moves 1 step
fast → moves 2 steps
If a loop exists, they will meet inside the cycle.
2. Find Starting Node of Loop
Once slow == fast:
Reset slow to head
Move both slow and fast one step at a time
The point where they meet again is the start of the loop
🧠 Why This Works

Let:

Distance from head to loop start = L
Distance from loop start to meeting point = D
Loop length = C

When slow and fast meet:

2 × (L + D) = L + D + k × C

Solving:

L = k × C - D

💻 Code Implementation

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if (slow == fast) {
                // Step 2: Find starting point
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow; // Start of loop
            }
        }

        return NULL; // No cycle
    }
};
