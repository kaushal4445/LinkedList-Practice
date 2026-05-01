# 🧹 Remove Duplicates from Sorted Doubly Linked List  
### ⚡ In-Place Deletion | 💻 C++ | 🔗 Pointer Manipulation

![DSA](https://img.shields.io/badge/DSA-Linked%20List-blue)
![Type](https://img.shields.io/badge/List-Doubly%20Linked-orange)
![Complexity](https://img.shields.io/badge/Time-O(n)-green)

---

## 📌 Problem Statement

Given a **sorted doubly linked list**, remove all duplicate nodes such that each element appears only once.

---

## ✨ Example

Input : 1 ⇄ 2 ⇄ 2 ⇄ 3 ⇄ 3 ⇄ 4
Output : 1 ⇄ 2 ⇄ 3 ⇄ 4


---

## 🧠 Approach

Since the list is **sorted**, duplicates will always be **adjacent**.

### 🔁 Strategy:
- Traverse the list using pointer `temp`
- If next node has same value:
  - Keep deleting duplicates
- Connect current node to next unique node

---

## 🔧 Algorithm Steps

1. Start from head  
2. For each node:
   - Check next node
   - If duplicate:
     - Delete node
     - Move forward
3. Update links:
   - `temp->next`
   - `nextNode->prev`
4. Continue traversal

---

## 💻 Implementation

```cpp
class Solution {
public:
    Node* removeDuplicates(Node* head) {
        Node* temp = head;

        while (temp != NULL && temp->next != NULL) {
            Node* nextNode = temp->next;

            while (nextNode != NULL && nextNode->data == temp->data) {
                Node* duplicate = nextNode;
                nextNode = nextNode->next;
                delete duplicate;
            }

            temp->next = nextNode;
            if (nextNode != NULL) {
                nextNode->prev = temp;
            }

            temp = temp->next;
        }

        return head;
    }
};


| Type     | Value    |
| -------- | -------- |
| ⏱ Time   | **O(n)** |
| 🧠 Space | **O(1)** |
