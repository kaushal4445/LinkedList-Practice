# 🔁 Rotate Linked List by K Positions

## 🚀 Problem
Given the head of a linked list, rotate the list to the right by **k places**.

---

## 💡 Easy Approach

### Steps:
1. Find length of linked list
2. Do `k = k % length`
3. Connect tail to head (make circular)
4. Find new last node → `(length - k)`
5. Break the link

---

## 🧠 Code (C++)

```cpp
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Helper function
ListNode* findNthNode(ListNode* temp, int k){
    int cnt = 1;
    while(temp != NULL){
        if(cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;

        // Step 1: Find length
        int len = 1;
        ListNode* tail = head;
        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }

        // Step 2: Optimize k
        if(k % len == 0) return head;
        k = k % len;

        // Step 3: Make circular
        tail->next = head;

        // Step 4: Find new last node
        ListNode* newLastNode = findNthNode(head, len - k);

        // Step 5: Break link
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};
```

---

## ⏱ Complexity
- Time: **O(N)**
- Space: **O(1)**

---

## 📌 Example

Input:
```
1 → 2 → 3 → 4 → 5, k = 2
```

Output:
```
4 → 5 → 1 → 2 → 3
```

---

## ✨ Author
Kaushal
