# 🔗 Reorder Linked List

## 📌 Problem

Given a singly linked list:

```
L0 → L1 → L2 → ... → Ln
```

Reorder it to:

```
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
```

⚠️ You must do this **in-place** without modifying node values.

---

## 💡 Approach (3-Step Efficient Method)

### ✅ Step 1: Find Middle

* Use **slow and fast pointer**
* Slow will point to the middle

### ✅ Step 2: Reverse Second Half

* Reverse the linked list from the middle

### ✅ Step 3: Merge Two Halves

* Alternate nodes from:

  * First half
  * Reversed second half

---

## ⚙️ Algorithm Steps

1. Find middle using slow-fast pointer
2. Reverse second half of list
3. Merge both halves alternately

---

## 🔄 Reverse Linked List (Recursive)

```cpp
ListNode* reverseLL (ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* last = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;

    return last;
}
```

---

## 🚀 Code Implementation

```cpp
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* rev = reverseLL(slow);

        // Step 3: Merge
        ListNode* curr = head;

        while(rev->next != NULL){
            ListNode* tempcurr = curr->next;
            curr->next = rev;

            ListNode* temprev = rev->next;
            rev->next = tempcurr;

            curr = tempcurr;
            rev = temprev;
        }
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)` (due to recursion stack)

---

## 🔍 Example

### Input:

```
1 → 2 → 3 → 4 → 5
```

### Output:

```
1 → 5 → 2 → 4 → 3
```

---

## 🧠 Key Insight

* Split the list into two halves
* Reverse second half
* Merge alternately

This avoids extra space and keeps operations efficient.

---

##
