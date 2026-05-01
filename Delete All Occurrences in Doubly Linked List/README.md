# 🧹 Delete All Occurrences in Doubly Linked List

## 📌 Problem Statement
Given a **doubly linked list**, delete all nodes that contain a given value `x`.

---

## 🧠 Approach

We traverse the doubly linked list and:
- If a node's value equals `x`:
  - Adjust pointers:
    - `prev -> next`
    - `next -> prev`
  - If it's the head node, update head
  - Delete the node
- Continue traversal safely using stored `nextNode`

---

## 🔧 Key Steps

1. Start from head
2. Traverse the list
3. For each node:
   - Store:
     - `nextNode`
     - `prevNode`
   - Update links
   - Delete node
4. Move to next node

---

## ⚡ Complexity

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## 💡 Important Points

- Always store `nextNode` before deleting
- Handle **head node separately**
- Carefully update both `prev` and `next` pointers

---

## 🧪 Example

### Input:

##code:

