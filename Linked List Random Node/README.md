# 🎯 Linked List Random Node — Solution Explanation

## 📌 Problem Statement

Given a singly linked list, design a solution such that:

* Each node's value can be returned randomly
* Every node has **equal probability** of being selected

---

## 💡 Approach Used: Array Conversion + Random Index

### 🔑 Idea

Since linked lists do not support direct/random access, we:

1. Traverse the linked list once
2. Store all node values into a dynamic array (`vector`)
3. Use a random index to fetch a value

---

## ⚙️ Implementation Breakdown

### 1. Storing Linked List Values

```cpp
vector<int> arr;
```

* A vector is used to store all node values.
* This allows constant-time access later.

---

### 2. Constructor Logic

```cpp
Solution(ListNode* head) {
    ListNode* temp = head;
    while(temp != NULL){
        arr.push_back(temp->val);
        temp = temp->next;
    }
}
```

#### Explanation:

* Start from the head of the linked list
* Traverse till the end
* Push each node’s value into the vector

✅ After this step, the linked list is converted into an array-like structure.

---

### 3. Generating a Random Node

```cpp
int getRandom() {
    int n = arr.size();
    int r_index = rand() % n;
    return arr[r_index];
}
```

#### Explanation:

* Get total number of elements (`n`)
* Generate a random index from `0` to `n-1`
* Return the value at that index

✅ Ensures equal probability for all elements

---

## ⏱️ Complexity Analysis

| Operation        | Complexity |
| ---------------- | ---------- |
| Constructor      | O(n)       |
| getRandom()      | O(1)       |
| Space Complexity | O(n)       |

---

## ✅ Advantages

* Very simple and easy to implement
* Fast random access (constant time)
* Suitable for small to medium-sized lists

---

## ⚠️ Limitations

* Uses extra memory (O(n))
* Not ideal for very large linked lists
* `rand()` may not provide perfectly uniform randomness in all environments

---

## 🚀 Optimized Alternative

For large datasets, consider:

* **Reservoir Sampling Algorithm**
* Uses **O(1) space**
* Still ensures equal probability

---

## 🧾 Summary

This approach converts the linked list into a vector for efficient random access.
Each call to `getRandom()` returns a random value using index-based selection, achieving constant time performance at the cost of additional space.

---
