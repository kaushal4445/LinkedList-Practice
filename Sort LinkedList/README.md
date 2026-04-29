# 🔗 Sort Linked List using Merge Sort (C++)

## 📌 Problem

Given the head of a singly linked list, sort the list in ascending order.

---

# 🚀 Approach: Merge Sort on Linked List

We use **Merge Sort** because:

* Linked lists don’t support random access
* Merge sort works efficiently with pointers
* Stable and guarantees **O(n log n)** time

---

# 🧠 Full Code with Explanation

```cpp
#include <iostream>
using namespace std;

// Definition of Linked List Node
struct ListNode {
    int val;
    ListNode* next;

    // Constructor
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:

    // 🔹 STEP 3: Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {

 ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }

    return dummyNode->next;
    }


    // 🔹 STEP 1: Find middle of linked list
    ListNode* getMid(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        // Fast moves 2 steps, slow moves 1
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;  // middle node
    }


    // 🔹 STEP 2: Sort the linked list
    ListNode* sortList(ListNode* head) {

        // Base case: 0 or 1 node → already sorted
        if (!head || !head->next)
            return head;

        // Find middle
        ListNode* mid = getMid(head);

        // Split list into two halves
        ListNode* right = mid->next;
        mid->next = NULL;

        ListNode* left = head;

        // Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge sorted halves
        return merge(left, right);
    }
};
```

---

# 🔍 Step-by-Step Working

## Example:

```
Input: 4 → 2 → 1 → 3
```

### 1️⃣ Divide

```
4 → 2 | 1 → 3
```

### 2️⃣ Divide again

```
4 | 2    and    1 | 3
```

### 3️⃣ Sort small lists

```
2 → 4    and    1 → 3
```

### 4️⃣ Merge

```
1 → 2 → 3 → 4
```

---

# 🔥 Key Concepts

### ✔ Slow & Fast Pointer

* Slow → 1 step
* Fast → 2 steps
* Helps find middle efficiently

---

### ✔ Dummy Node Trick

* Avoids special cases for first node
* Makes merging logic simple

---

### ✔ Recursion

* Breaks problem into smaller parts
* Combines sorted results

---

# 📊 Complexity Analysis

| Type  | Value      |
| ----- | ---------- |
| Time  | O(n log n) |
| Space | O(log n)   |

---

# ⚠️ Edge Cases

* Empty list → return NULL
* Single node → already sorted
* Duplicate values → handled correctly

---

# 💡 Interview Tips

👉 Why Merge Sort for Linked List?

Because:

* No random access (unlike arrays)
* Splitting is easy using pointers
* Merging is efficient

---

# 🧪 Optional Test Case

```cpp
// Example usage
// Input: 4 -> 2 -> 1 -> 3
// Output: 1 -> 2 -> 3 -> 4
```

---

# 👨‍💻 Author

Your Name
