# Add Two Numbers II

LeetCode Problem: **445. Add Two Numbers II**

---

# Problem Statement

You are given two non-empty linked lists representing two non-negative integers.

- The most significant digit comes first.
- Each node contains a single digit.
- Add the two numbers and return the sum as a linked list.

You may not reverse the input using extra arrays or converting into integers.

---

# Example

## Input

```text
l1 = 7 -> 2 -> 4 -> 3
l2 = 5 -> 6 -> 4
```

## Output

```text
7 -> 8 -> 0 -> 7
```

---

# Explanation

The numbers represented are:

```text
7243
+564
----
7807
```

Result linked list:

```text
7 -> 8 -> 0 -> 7
```

---

# Intuition

The digits are stored in forward order.

Normal addition starts from the last digit.

So first:

- Reverse both linked lists
- Add digits normally
- Build answer in forward order

---

# Full Code

```cpp
ListNode* reverseLL(ListNode* head) {

    // Base case
    if(head == NULL || head->next == NULL) {
        return head;
    }

    // Reverse remaining list
    ListNode* last = reverseLL(head->next);

    // Reverse current connection
    head->next->next = head;
    head->next = NULL;

    return last;
}

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Reverse both lists
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        int sum = 0;
        int carry = 0;

        // Dummy answer node
        ListNode* ans = new ListNode();

        while(l1 != NULL || l2 != NULL) {

            // Add l1 digit
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add l2 digit
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Current digit
            ans->val = sum % 10;

            // Carry
            carry = sum / 10;

            // Create new node
            ListNode* newNode = new ListNode(carry);

            // Attach at front
            newNode->next = ans;
            ans = newNode;

            // Reset sum with carry
            sum = carry;
        }

        // If carry is 0 skip extra node
        return carry == 0 ? ans->next : ans;
    }
};
```

---

# Step-by-Step Dry Run

---

# Input

```text
l1 = 7 -> 2 -> 4 -> 3
l2 = 5 -> 6 -> 4
```

---

# Step 1: Reverse Both Lists

After reversing:

```text
l1 = 3 -> 4 -> 2 -> 7
l2 = 4 -> 6 -> 5
```

Now addition becomes easy.

---

# Step 2: Start Addition

Initialize:

```text
carry = 0
```

---

# Iteration 1

```text
3 + 4 = 7
```

Digit:

```text
7 % 10 = 7
```

Carry:

```text
7 / 10 = 0
```

Answer:

```text
7
```

---

# Iteration 2

```text
4 + 6 + 0 = 10
```

Digit:

```text
0
```

Carry:

```text
1
```

Answer:

```text
0 -> 7
```

---

# Iteration 3

```text
2 + 5 + 1 = 8
```

Digit:

```text
8
```

Carry:

```text
0
```

Answer:

```text
8 -> 0 -> 7
```

---

# Iteration 4

```text
7 + 0 = 7
```

Answer:

```text
7 -> 8 -> 0 -> 7
```

---

# Final Output

```text
7 -> 8 -> 0 -> 7
```

---

# Reverse Linked List Explanation

---

## Recursive Reverse

```cpp
ListNode* reverseLL(ListNode* head)
```

---

# Example

```text
1 -> 2 -> 3
```

Recursive calls:

```text
reverse(1)
   reverse(2)
      reverse(3)
```

Now reverse connections while returning.

---

# Backtracking

```cpp
head->next->next = head;
```

Makes:

```text
2 -> 1
3 -> 2
```

---

# Final Reversed List

```text
3 -> 2 -> 1
```

---

# Visual Diagram

---

## Original Lists

```text
7 -> 2 -> 4 -> 3
5 -> 6 -> 4
```

---

## After Reverse

```text
3 -> 4 -> 2 -> 7
4 -> 6 -> 5
```

---

## Addition Process

```text
3 + 4 = 7
4 + 6 = 10
2 + 5 + 1 = 8
7 + 0 = 7
```

---

## Final Result

```text
7 -> 8 -> 0 -> 7
```

---

# Important Concepts Used

---

## 1. Recursive Linked List Reversal

Efficient recursive reversal using backtracking.

---

## 2. Carry Handling

Same as normal mathematical addition.

---

## 3. Head Insertion

New nodes are inserted at front to maintain forward order.

---

# Time Complexity

Reversing lists:

```text
O(N + M)
```

Addition:

```text
O(max(N,M))
```

Total:

```text
O(N + M)
```

---

# Space Complexity

Recursive stack:

```text
O(N + M)
```

---

# Key Learning

This problem teaches:

- Recursive linked list reversal
- Linked list addition
- Carry propagation
- Pointer manipulation
- Building result in forward order

---

# Related Problems

- Add Two Numbers
- Reverse Linked List
- Reverse Linked List II
- Plus One Linked List

---

# Author

Made with ❤️ for DSA Practice
