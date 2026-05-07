# Insertion Sort on Linked List

LeetCode Problem: **147. Insertion Sort List**

---

# Problem Statement

Given the head of a singly linked list, sort the list using **Insertion Sort** and return the sorted list.

---

# Example

## Input

```text
4 -> 2 -> 1 -> 3
```

## Output

```text
1 -> 2 -> 3 -> 4
```

---

# What is Insertion Sort?

Insertion Sort works by:

- Taking one element at a time
- Placing it in its correct position
- Building the sorted list gradually

In arrays, elements are shifted.

In linked lists, we change pointers instead.

---

# Intuition

We create a new sorted linked list.

For every node from original list:

1. Find correct position
2. Insert node there
3. Continue until all nodes are sorted

---

# Full Code

```cpp
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        // Dummy node for sorted list
        ListNode* dummyNode = new ListNode(0);

        while(head != NULL) {

            // Store next node
            ListNode* next = head->next;

            // Start from beginning of sorted list
            ListNode* temp = dummyNode;

            // Find correct position
            while(temp->next && temp->next->val < head->val) {
                temp = temp->next;
            }

            // Insert node
            head->next = temp->next;
            temp->next = head;

            // Move to next node
            head = next;
        }

        return dummyNode->next;
    }
};
```

---

# Step-by-Step Dry Run

## Input

```text
4 -> 2 -> 1 -> 3
```

---

# Step 1: Create Dummy Node

```text
dummy -> NULL
```

This dummy node helps us build the sorted list easily.

---

# Iteration 1

## Current Node

```text
4
```

Sorted list is empty.

Insert `4`.

## Result

```text
dummy -> 4
```

---

# Iteration 2

## Current Node

```text
2
```

Check sorted list:

```text
4
```

Since:

```text
2 < 4
```

Insert before `4`.

## Result

```text
dummy -> 2 -> 4
```

---

# Iteration 3

## Current Node

```text
1
```

Compare with sorted list:

```text
1 < 2
```

Insert at beginning.

## Result

```text
dummy -> 1 -> 2 -> 4
```

---

# Iteration 4

## Current Node

```text
3
```

Traverse sorted list:

```text
1 -> 2 -> 4
```

Correct position is between `2` and `4`.

## Result

```text
dummy -> 1 -> 2 -> 3 -> 4
```

---

# Final Output

```text
1 -> 2 -> 3 -> 4
```

---

# Visual Diagram

---

## Original List

```text
4 -> 2 -> 1 -> 3
```

---

## After Inserting 4

```text
dummy -> 4
```

---

## After Inserting 2

```text
dummy -> 2 -> 4
```

---

## After Inserting 1

```text
dummy -> 1 -> 2 -> 4
```

---

## After Inserting 3

```text
dummy -> 1 -> 2 -> 3 -> 4
```

---

# Important Code Explanation

---

## 1. Store Next Node

```cpp
ListNode* next = head->next;
```

Why?

Because after insertion, links change.

So we save next node before modifying pointers.

---

## 2. Find Correct Position

```cpp
while(temp->next && temp->next->val < head->val)
```

Move until:

- next value becomes greater
OR
- list ends

---

## 3. Insert Node

```cpp
head->next = temp->next;
temp->next = head;
```

This inserts current node in sorted list.

---

# Why Dummy Node?

Without dummy node:

- insertion at beginning becomes difficult
- many edge cases appear

Dummy node simplifies code.

---

# Time Complexity

For every node, we may traverse sorted list.

```text
O(N²)
```

---

# Space Complexity

Only pointers are used.

```text
O(1)
```

---

# Key Learning

This problem teaches:

- Linked list insertion
- Pointer manipulation
- Building sorted list
- Insertion sort logic
- Dummy node usage

---

# Related Problems

- Sort List
- Merge Two Sorted Lists
- Reverse Linked List
- Partition List

---

# Author

Made with ❤️ for DSA Practice
