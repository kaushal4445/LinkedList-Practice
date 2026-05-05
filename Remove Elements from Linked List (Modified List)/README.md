# 🧩 Remove Elements from Linked List (Modified List)

## 📌 Problem

You are given:

* A linked list `head`
* An array `nums`

👉 Task: Remove all nodes from the linked list whose values are present in `nums`.

---

## 💡 Approach (Easy to Understand)

### 🔹 Core Idea:

We need a **fast way to check** whether a value exists in `nums`.

👉 So we use:

* **`unordered_set`** → for **O(1)** lookup

---

### 🔹 Step-by-Step:

1. Convert `nums` → `unordered_set`
2. Remove unwanted nodes from the **start (head)**
   (because head can change)
3. Traverse remaining list:

   * If value **NOT in set** → move forward
   * If value **IN set** → remove node

---

## 🧠 Why This Works

* Set gives **instant lookup**
* We traverse list only **once**
* Efficient for large inputs

---

## 🧪 Example

### Input:

```
nums = [2, 4]
Linked List: 1 → 2 → 3 → 4 → 5
```

### Process:

* Remove 2 ❌
* Remove 4 ❌

### Output:

```
1 → 3 → 5
```

---

## 🔍 Dry Run (Important)

```
List: 1 → 2 → 3 → 4 → 5
Set: {2, 4}

Step 1: 1 → keep
Step 2: 2 → remove
Step 3: 3 → keep
Step 4: 4 → remove
Step 5: 5 → keep

Final: 1 → 3 → 5
```

---

## 🚀 Code (C++)

```cpp
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        // Step 1: Store nums in set
        unordered_set<int> st(begin(nums), end(nums));

        ListNode* prev = NULL;
        ListNode* curr = head;

        // Step 2: Remove nodes from beginning
        while (curr != NULL && st.count(curr->val)) {
            head = curr->next;
            curr = head;
        }

        // Step 3: Traverse remaining list
        while (curr != NULL) {
            int currVal = curr->val;

            if (!st.count(currVal)) {
                prev = curr;
                curr = curr->next;
            } else {
                prev->next = curr->next;
                curr = curr->next;
            }
        }

        return head;
    }
};
```

---

## ⚡ Complexity

* **Time Complexity:** `O(n + m)`
  (n = list size, m = nums size)

* **Space Complexity:** `O(m)`
  (for storing set)

---

## 🎯 Key Points (Exam / Interview)

* Always handle **head separately**
* Use **set for fast lookup**
* Carefully update **prev pointer**
* One pass solution → efficient

---

## ✅ Summary

👉 Convert array → set
👉 Remove matching nodes
👉 Traverse once

✔ Fast
✔ Clean
✔ Interview-ready

---
