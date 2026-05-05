# 🧩 Remove Elements from Linked List

## 📌 Problem

Given the head of a linked list and an integer `val`, remove all nodes of the linked list that have value equal to `val`.

---

## 💡 Approach (Simple & Interview-Friendly)

### 🔹 Core Idea:

Use a **dummy node** to simplify deletion, especially when the **head itself needs to be removed**.

---

### 🔹 Why Dummy Node?

Normally, deleting the head is tricky.
👉 Dummy node helps us treat **all nodes equally** (including head).

---

### 🔹 Step-by-Step:

1. Create a **dummy node** pointing to head
2. Use a pointer `temp` starting from dummy
3. Traverse the list:

   * If `temp->next->val == val` → remove node
   * Else → move forward
4. Return `dummy->next` (new head)

---

## 🧠 Key Insight

👉 We always check **`temp->next`**, not `temp`
Because we need to **delete the next node safely**

---

## 🧪 Example

### Input:

```text
Linked List: 1 → 2 → 6 → 3 → 4 → 5 → 6
val = 6
```

### Process:

* Remove 6 ❌
* Remove 6 ❌

### Output:

```text
1 → 2 → 3 → 4 → 5
```

---

## 🔍 Dry Run

```text
Dummy → 1 → 2 → 6 → 3 → 4 → 5 → 6

Step 1: 1 → keep  
Step 2: 2 → keep  
Step 3: 6 → remove  
Step 4: 3 → keep  
Step 5: 4 → keep  
Step 6: 5 → keep  
Step 7: 6 → remove  

Final: 1 → 2 → 3 → 4 → 5
```

---

## 🚀 Code (C++)

```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummynode = new ListNode(0);
        dummynode->next = head;

        ListNode* temp = dummynode;

        while (temp->next != NULL) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return dummynode->next;
    }
};
```

---

## ⚡ Complexity

* **Time Complexity:** `O(n)`
  (traverse list once)

* **Space Complexity:** `O(1)`
  (no extra space used)

---

## 🎯 Key Points (Important)

* Dummy node avoids **special case for head**
* Always check **`temp->next`**
* Do NOT move pointer when deleting
* Clean and optimal solution

---

## ✅ Summary

👉 Use dummy node
👉 Traverse once
👉 Remove matching nodes

✔ Simple
✔ Efficient
✔ Must-know pattern for Linked List

---
