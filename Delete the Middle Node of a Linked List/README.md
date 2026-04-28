# 🚀 Delete Middle Node of a Linked List (C++)

## 📌 Problem Statement
Given the `head` of a singly linked list, delete the **middle node** and return the updated list.

👉 If there are two middle nodes, delete the **second middle node**.

---

## 🧠 Approach: Fast & Slow Pointer

We use the **two-pointer technique**:
- `slow` pointer → moves 1 step
- `fast` pointer → moves 2 steps

### 💡 Idea:
- When `fast` reaches the end,
- `slow` will be at the **middle node**

We also maintain a `prev` pointer to track the node **before the middle node**, so we can delete it easily.

---

## ⚙️ Algorithm Steps

1. Handle edge case:
   - If list is empty or has only one node → return `NULL`
2. Initialize:
   - `slow = head`
   - `fast = head`
   - `prev = NULL`
3. Traverse the list:
   - Move `slow` by 1 step
   - Move `fast` by 2 steps
   - Update `prev = slow`
4. When loop ends:
   - `slow` is at middle node
5. Delete middle node:
   - `prev->next = slow->next`
   - `delete slow`
6. Return updated `head`

---

## 🧪 Example

### Input:

1 → 2 → 3 → 4 → 5


### Output:


👉 Only one node → after deletion, list becomes empty.

---

## ⏱️ Complexity Analysis

| Type | Complexity |
|------|----------|
| Time Complexity | O(n) |
| Space Complexity | O(1) |

---

## 💻 Implementation (C++)

```cpp
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
        delete slow;

        return head;
    }
};
