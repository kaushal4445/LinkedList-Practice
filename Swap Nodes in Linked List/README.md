# 🔄 Swap Nodes in Linked List — Solution & Approach

## 📌 Problem Statement

Given the head of a singly linked list and an integer `k`, swap the values of:

* The **k-th node from the beginning**
* The **k-th node from the end**

Return the modified linked list.

---

## 💡 Approach Used: Two-Pointer Technique

### 🔑 Core Idea

Instead of finding the length first, we:

* Traverse the list once
* Use two pointers to locate both required nodes efficiently
* Swap their values

---

## ⚙️ Code Implementation

```cpp
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* person1 = NULL;
        ListNode* person2 = NULL;

        ListNode* temp = head;
        while(temp != NULL){
            if(person2 != NULL)
                person2 = person2->next;

            k--;
            if(k == 0){
                person1 = temp;
                person2 = head;
            }
            temp = temp->next;
        }
        swap(person1->val, person2->val);
        return head;       
    }
};
```

---

## 🧠 Step-by-Step Explanation

### 1. Initialize Pointers

```cpp
ListNode* person1 = NULL;
ListNode* person2 = NULL;
```

* `person1` → will point to k-th node from start
* `person2` → will point to k-th node from end

---

### 2. Traverse the List

```cpp
while(temp != NULL)
```

#### Inside Loop:

### 📍 Step A: Move `person2` (if already initialized)

```cpp
if(person2 != NULL)
    person2 = person2->next;
```

* Once `person2` starts, it moves along with `temp`

---

### 📍 Step B: Decrease k

```cpp
k--;
```

---

### 📍 Step C: When k becomes 0

```cpp
if(k == 0){
    person1 = temp;
    person2 = head;
}
```

* `person1` is fixed at k-th node from start
* `person2` starts from head

👉 From here:

* `temp` continues till end
* `person2` moves alongside
* When `temp` reaches end, `person2` reaches k-th node from end

---

### 3. Swap Values

```cpp
swap(person1->val, person2->val);
```

* Swap values instead of nodes (simpler and safer)

---

## 🎯 Key Insight

> By the time `temp` reaches the end, `person2` automatically lands on the k-th node from the end.

---

## ⏱️ Complexity Analysis

| Operation | Complexity |
| --------- | ---------- |
| Traversal | O(n)       |
| Space     | O(1)       |

---

## ✅ Advantages

* Only **one traversal** needed
* No need to calculate length
* Constant space usage

---

## ⚠️ Important Notes

* This swaps **values**, not actual nodes
* Works efficiently even for large lists
* Ensure `k` is valid (1 ≤ k ≤ length of list)

---

## 🚀 Alternative Approach

* Compute length first
* Find both nodes separately
* Swap values

👉 But that requires **two passes**, while this approach uses only **one**

---

## 🧾 Summary

This solution uses a **two-pointer technique** to locate both the k-th node from the start and the k-th node from the end in a single traversal. Once found, their values are swapped to produce the final result efficiently.

---
