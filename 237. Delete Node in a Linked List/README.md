🗑️ Delete Node in a Linked List (Without Head)
📌 Problem Statement

You are given a node in a singly linked list, and you need to delete it.

❗ Important Constraint:

You are NOT given the head of the linked list.
You only have access to the node that needs to be deleted.
💡 Approach Used (Your Code)

Instead of directly deleting the node (which requires access to the previous node), we:

Copy values forward from the next nodes.
Continue shifting values until reaching the last node.
Delete the last node.
🧠 Code Implementation
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* previous = NULL;

        // Shift values forward
        while (node != NULL && node->next != NULL) {
            node->val = node->next->val; // Copy next node value
            previous = node;             // Track previous node
            node = node->next;           // Move forward
        }

        // Remove last node
        previous->next = NULL;
        delete (node);
    }
};
🔄 Step-by-Step Visualization
🎯 Initial List
4 → 5 → 1 → 9
      ↑ (node to delete)
🔁 After Value Shifting
4 → 1 → 9 → 9
✂️ After Deleting Last Node
4 → 1 → 9
⚙️ Complexity Analysis
Type	Complexity
⏱ Time	O(n)
🧠 Space	O(1)
⚠️ Important Notes
🚫 Cannot delete the last node using this approach.
🔁 Traverses the list → not optimal.
🧹 Proper memory cleanup is done using delete.
🚀 Optimal Approach (Recommended)

Instead of shifting all values, we can do it in O(1):

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};
🆚 Comparison
Approach	Time Complexity	Idea
Your Approach	O(n)	Shift all values forward
Optimal Approach	O(1)	Copy next & delete it
🎯 Key Takeaway

When you don’t have access to the previous node,
👉 modify the current node instead of deleting it directly.
