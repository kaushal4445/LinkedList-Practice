# 🔀 Partition Linked List (Around Value x)

## 🚀 Problem
Given the head of a linked list and a value `x`, partition the list such that:

- All nodes **less than x** come before nodes **greater than or equal to x**
- The **relative order** of nodes in each partition should remain the same

---

## 💡 Approach (Easy & Efficient)

We use **two dummy linked lists**:

1. **Small list** → nodes with values `< x`
2. **Large list** → nodes with values `>= x`

### Steps:
1. Create two dummy nodes: `small` and `large`
2. Traverse the original list
3. Attach nodes to:
   - `small` list if value `< x`
   - `large` list otherwise
4. Connect small list to large list
5. Return the head of the new list

---

## 🧠 Code (C++)

```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);

        ListNode* smallPointer = small;
        ListNode* largePointer = large;

        while(head != NULL){
            if(head->val < x){
                smallPointer->next = head;
                smallPointer = smallPointer->next;
            }
            else{
                largePointer->next = head;
                largePointer = largePointer->next;
            }
            head = head->next;
        }

        // Connect both lists
        smallPointer->next = large->next;
        largePointer->next = NULL;

        return small->next;
    }
};
```

---

## 📌 Example

Input:
```
1 → 4 → 3 → 2 → 5 → 2, x = 3
```

Output:
```
1 → 2 → 2 → 4 → 3 → 5
```

---

## ⏱ Complexity

- **Time Complexity:** O(N)  
- **Space Complexity:** O(1) (only extra pointers used)

---

## 🎯 Key Concepts

- Linked List Traversal  
- Dummy Nodes  
- Two-pointer technique  
- Stable partitioning  

---

## ✨ Author
Kaushal
