# 🔄 Swap Nodes in Pairs (Linked List)


---

## 📌 Problem

Given the head of a singly linked list, swap every two adjacent nodes and return the modified list.

* You must **not modify node values**
* Only change the **links (pointers)**

---

## 💡 Approach: Recursion

### 🔑 Core Idea

* Swap the first two nodes
* Recursively solve the remaining list
* Connect the swapped pair with the result of recursion

---

## ⚙️ Solution Code

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;

        return temp;
    }
};
```

---

## 🧠 Step-by-Step Explanation

### 1. Base Case

```cpp
if(head == NULL || head->next == NULL)
    return head;
```

* If list is empty or has only one node → no swap needed

---

### 2. Identify Nodes to Swap

```cpp
ListNode* temp = head->next;
```

* `head` → first node
* `temp` → second node

---

### 3. Recursive Call

```cpp
head->next = swapPairs(head->next->next);
```

* Skip two nodes
* Recursively swap the remaining list
* Attach result to current pair

---

### 4. Perform Swap

```cpp
temp->next = head;
```

* Reverse the link between the two nodes

---

### 5. Return New Head

```cpp
return temp;
```

* After swapping, second node becomes new head

---

## 🔁 Example

### Input:

```
1 → 2 → 3 → 4
```

### Output:

```
2 → 1 → 4 → 3
```

---

## 🎯 Key Insight

> Break the problem into smaller subproblems (pairs), solve recursively, and connect results.

---

## ⏱️ Complexity Analysis

| Type             | Complexity             |
| ---------------- | ---------------------- |
| Time Complexity  | O(n)                   |
| Space Complexity | O(n) (recursion stack) |

---

## ✅ Advantages

* Clean and elegant solution
* Easy to understand recursion flow
* No extra data structures used

---

## ⚠️ Notes

* Uses recursion → stack space required
* Iterative approach can reduce space to O(1)

---

## 🚀 Alternative Approach

* Iterative method using pointers
* More optimal in terms of space (O(1))

---

## 🧾 Summary

This solution uses a **recursive approach** to swap adjacent nodes in pairs. It swaps the first two nodes, then recursively processes the rest of the list and connects the results efficiently.

---
