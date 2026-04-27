🔁 Detect Cycle in Linked List

This project demonstrates how to efficiently detect whether a singly linked list contains a cycle using Floyd’s Cycle Detection Algorithm (Tortoise and Hare).

🚀 Approach Overview

To determine if a linked list has a loop, we use two pointers:

Slow Pointer (slow) → moves one step at a time
Fast Pointer (fast) → moves two steps at a time
🔍 Key Idea
If there is no cycle, fast will reach NULL
If there is a cycle, fast and slow will eventually meet
🧠 Algorithm Steps
Initialize:
slow = head
fast = head
Traverse the list:
Move slow by one step → slow = slow->next
Move fast by two steps → fast = fast->next->next
Check:
If slow == fast → cycle exists → return true
If loop ends:
No cycle → return false
💻 Code Implementation
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};
⏱️ Complexity Analysis
Metric	Value
Time Complexity	O(N)
Space Complexity	O(1)
Traverses the list at most once
Uses constant extra space
📌 Key Points
No modification to the linked list
Efficient and optimal solution
Works even for large inputs
Handles edge cases:
Empty list
Single node (with/without self-loop)
✅ Example

Input:

1 → 2 → 3 → 4
     ↑     ↓
     ← ← ←

Output:

true
❌ Example (No Cycle)

Input:

1 → 2 → 3 → 4 → NULL

Output:

false
🔄 Related Problems
Find length of loop
Find starting node of cycle
Remove cycle from linked list
🛠️ Use Cases
Detecting infinite loops in programs
Memory cycle detection
Graph-related cycle problems
