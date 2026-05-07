# Reverse Linked List II

LeetCode Problem: **92. Reverse Linked List II**

## Problem Statement

Given the head of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return the reversed list.

---

# Example

## Input

```text
head = 1 -> 2 -> 3 -> 4 -> 5
left = 2
right = 4
```

## Output

```text
1 -> 4 -> 3 -> 2 -> 5
```

---

# Intuition

We only need to reverse a specific portion of the linked list.

Instead of reversing the entire list:

- Reach the node before `left`
- Reverse nodes one by one
- Reconnect the list

This approach is called:

# Head Insertion Technique

---

# Full Code

```cpp
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // If list is empty or has one node
        if(head == NULL || head->next == NULL)
            return head;

        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // prev will point to node before left position
        ListNode* prev = dummy;

        // Move prev to (left-1)th node
        for(int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr points to first node of reversing part
        ListNode* curr = prev->next;

        // Reverse nodes using head insertion
        for(int i = 1; i <= right-left; i++) {

            ListNode* temp = prev->next;

            prev->next = curr->next;

            curr->next = curr->next->next;

            prev->next->next = temp;
        }

        return dummy->next;
    }
};
```

---

# Step-by-Step Dry Run

## Initial Linked List

```text
1 -> 2 -> 3 -> 4 -> 5
```

We want to reverse from:

```text
left = 2
right = 4
```

---

# Step 1: Create Dummy Node

```text
0 -> 1 -> 2 -> 3 -> 4 -> 5
^
dummy
```

Dummy node helps when reversal starts from head.

---

# Step 2: Move `prev`

Loop:

```cpp
for(int i =1; i<left; i++)
```

After loop:

```text
dummy -> 1 -> 2 -> 3 -> 4 -> 5
         ^
        prev
```

`prev` points to node before reversal section.

---

# Step 3: Set `curr`

```cpp
curr = prev->next;
```

```text
1 -> 2 -> 3 -> 4 -> 5
     ^
    curr
```

---

# Reversal Process

We perform:

```cpp
right-left
```

operations.

Here:

```text
4 - 2 = 2
```

So loop runs 2 times.

---

# Iteration 1

## Current List

```text
1 -> 2 -> 3 -> 4 -> 5
```

### temp

```cpp
temp = prev->next;
```

```text
temp = 2
```

---

## Move node after curr to front

```cpp
prev->next = curr->next;
```

```text
1 -> 3 -> 4 -> 5
     ^
```

---

## Disconnect moved node

```cpp
curr->next = curr->next->next;
```

```text
2 -> 4 -> 5
```

---

## Attach moved node before temp

```cpp
prev->next->next = temp;
```

Now:

```text
1 -> 3 -> 2 -> 4 -> 5
```

---

# Iteration 2

Current:

```text
1 -> 3 -> 2 -> 4 -> 5
```

Move `4` in front of `3`

Final:

```text
1 -> 4 -> 3 -> 2 -> 5
```

---

# Final Output

```text
1 -> 4 -> 3 -> 2 -> 5
```

---

# Diagram Explanation

## Before Reversal

```text
dummy -> 1 -> 2 -> 3 -> 4 -> 5
           ^
          prev
                ^
               curr
```

---

## After First Iteration

```text
dummy -> 1 -> 3 -> 2 -> 4 -> 5
```

---

## After Second Iteration

```text
dummy -> 1 -> 4 -> 3 -> 2 -> 5
```

---

# Important Concepts Used

## 1. Dummy Node

Used to handle edge cases easily.

Example:

- reversing from head
- single node reversal

---

## 2. Head Insertion Technique

We repeatedly:

- take next node
- move it to front

without changing entire list.

---

# Time Complexity

We traverse list once.

```text
O(N)
```

---

# Space Complexity

Only pointers used.

```text
O(1)
```

---

# Key Learning

This problem teaches:

- Linked list pointer manipulation
- In-place reversal
- Dummy node usage
- Head insertion technique

---

# Related Problems

- Reverse Linked List
- Reverse Nodes in K Group
- Palindrome Linked List
- Reorder List

---

# Author

Made with ❤️ for DSA Practice
