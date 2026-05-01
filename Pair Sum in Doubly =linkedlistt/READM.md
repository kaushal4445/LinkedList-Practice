# 🔍 Find Pairs with Given Sum in Doubly Linked List  
### ⚡ Two Pointer Technique | 💻 C++ | 🚀 O(n) Optimized

![DSA](https://img.shields.io/badge/DSA-Doubly%20Linked%20List-blue)
![Technique](https://img.shields.io/badge/Technique-Two%20Pointers-orange)
![Complexity](https://img.shields.io/badge/Time-O(n)-green)

---

## 📌 Problem Statement

Given a **sorted doubly linked list**, find all pairs of nodes whose sum equals a given target.

---

## ✨ Example

Target : 5

Output : (1,4), (2,3)


---

## 🧠 Approach (Two Pointer Technique)

Instead of using brute force (O(n²)), we use:
- `left` pointer → start (smallest)
- `right` pointer → end (largest)

### 🔁 Logic:
- If sum == target → store pair
- If sum < target → move `left++`
- If sum > target → move `right--`

---

## 🔧 Helper Function

```cpp
Node* findTail(Node* head) {
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }



| Type     | Value    |
| -------- | -------- |
| ⏱ Time   | **O(n)** |
| 🧠 Space | **O(1)** |

    return tail;
}
