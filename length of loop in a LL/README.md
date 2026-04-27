🔁 Detect and Measure Loop Length in Linked List

This project demonstrates how to detect a cycle (loop) in a singly linked list and calculate its length using Floyd’s Cycle Detection Algorithm (also known as the Tortoise and Hare algorithm).

🚀 Approach Overview

The solution works in two main steps:

1. Detect Loop
Use two pointers:
slow moves one step at a time
fast moves two steps at a time
If a loop exists, both pointers will eventually meet.
2. Count Loop Length
Once a loop is detected (i.e., slow == fast), we:
Keep one pointer fixed
Move the other pointer until it comes back to the same node
Count the number of steps taken → this is the loop length
🧠 Algorithm
Initialize slow and fast to head
Traverse the list:
slow = slow->next
fast = fast->next->next
If slow == fast, a loop exists
Call helper function to count loop length
If no loop is found, return 0
💻 Code Implementation
int countLoopLength(Node* slow, Node* fast) {
    int count = 1;
    fast = fast->next;

    while (slow != fast) {
        count++;
        fast = fast->next;
    }

    return count;
}

class Solution {
public:
    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return countLoopLength(slow, fast);
        }

        return 0; // No loop
    }
};
⏱️ Complexity Analysis
Operation	Complexity
Time Complexity	O(N)
Space Complexity	O(1)
Traverses the list at most twice
No extra space used
📌 Key Points
Efficient cycle detection using two pointers
No modification to the linked list
Works in constant space
Handles edge cases (no loop, single node, etc.)
✅ Example

Input:

1 → 2 → 3 → 4 → 5
          ↑     ↓
          ← ← ←

Output:

3
🛠️ Use Cases
Detecting infinite loops in linked structures
Memory leak detection
Graph cycle detection (adaptation)
