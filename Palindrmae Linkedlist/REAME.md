🔁 Palindrome Linked List

Check whether a singly linked list is a palindrome using an efficient in-place approach (O(1) space).

📌 Problem Statement

Given the head of a singly linked list, return true if it is a palindrome, otherwise return false.

🧠 Example
Input:  1 → 2 → 2 → 1  
Output: true

Input:  1 → 2 → 3  
Output: false

🚀 Approach
1️⃣ Find the Middle

Use slow and fast pointers

slow moves 1 step
fast moves 2 steps
➡️ When fast reaches end, slow is at middle
2️⃣ Reverse Second Half

Reverse the linked list starting from the middle node

3️⃣ Compare Both Halves

Compare values from:

Start of list
Start of reversed half
4️⃣ Restore List

Reverse second half again to keep original structure intact

⚡ Complexity
Type	Value
Time	O(n)
Space	O(1)
💻 C++ Code
struct ListNode {
    int val;
    ListNode *next;
};

// Reverse function
ListNode* reverse(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* newHead = reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow);

        ListNode* first = head;
        ListNode* second = newHead;

        while (second != NULL) {
            if (first->val != second->val) {
                reverse(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }

        reverse(newHead);
        return true;
    }
};

🔍 Code Explanation
🔁 Reverse Function
ListNode* reverse(ListNode* head)


👉 This function reverses a linked list using recursion

Steps:
Base Case
if (head == NULL || head->next == NULL)


➡️ If list is empty or has one node → already reversed

Recursive Call
ListNode* newHead = reverse(head->next);


➡️ Reverse the rest of the list

Reverse Current Link
head->next->next = head;
head->next = NULL;


➡️ Change direction of pointer

Return New Head
return newHead;

🔍 isPalindrome Function
🟢 Step 1: Handle Edge Cases
if (head == NULL || head->next == NULL)


➡️ Empty or single node list is always palindrome

🟢 Step 2: Find Middle
while (fast && fast->next)


➡️ Move:

slow → 1 step
fast → 2 steps

➡️ slow reaches middle

🟢 Step 3: Reverse Second Half
ListNode* newHead = reverse(slow);


➡️ Reverse from middle to end

🟢 Step 4: Compare Halves
while (second != NULL)


➡️ Compare:

if (first->val != second->val)


❌ If mismatch → not palindrome
✔ If all match → palindrome

🟢 Step 5: Restore List
reverse(newHead);


➡️ Restore original linked list structure

📷 Visualization
Original:
1 → 2 → 2 → 1

Middle:
1 → 2 | 2 → 1

Reversed Half:
1 → 2 | 1 → 2

Comparison:
1 == 1 ✔
2 == 2 ✔

🎯 Key Concepts
Two Pointer Technique
Recursion
Linked List Manipulation
In-place Optimization
🏁 Final Thoughts

This problem is a must-know for interviews because it tests:

Pointer logic
Optimization skills
Clean coding approach
