# 🧩 Delete Middle Node of Linked List

## 📌 Problem Statement

Given the **head of a singly linked list**, delete the **middle node**
and return the modified list.

------------------------------------------------------------------------

## 🧠 Intuition

We use the **🐢 Slow & 🐇 Fast Pointer Technique**: - Slow moves 1
step - Fast moves 2 steps\
👉 When fast reaches the end, slow is at the middle

------------------------------------------------------------------------

## 🚀 Approach

1.  Handle edge case (0 or 1 node → return NULL)
2.  Use three pointers: slow, fast, prev
3.  Find middle node
4.  Delete it using prev pointer

------------------------------------------------------------------------

## 💻 Code

``` cpp
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete(slow);

        return head;
    }
};
```

------------------------------------------------------------------------

## 🔄 Example

Before: 1 → 2 → 3 → 4 → 5

After: 1 → 2 → 4 → 5

------------------------------------------------------------------------

## ⚙️ Complexity

-   Time: O(n)
-   Space: O(1)

------------------------------------------------------------------------

## ⚠️ Edge Cases

-   Single node → NULL
-   Even nodes → second middle deleted

------------------------------------------------------------------------

## 🎯 Key Takeaway

Fast pointer helps slow pointer reach the middle efficiently.

------------------------------------------------------------------------

## 🏷️ Tags

Linked List, Two Pointer, DSA
