# 🔁 Remove Duplicates from Sorted Linked List II (C++)

This repository explains an efficient approach to solve:

> ❗ Remove **all nodes that have duplicates**, leaving only distinct values.

---

## 📌 Problem Statement

Given the `head` of a **sorted linked list**, delete all nodes that have duplicate numbers, so only unique elements remain.

---

## 🧾 Example

```text
Input:  1 → 2 → 3 → 3 → 4 → 4 → 5  
Output: 1 → 2 → 5
```

```text
Input:  1 → 1 → 1 → 2 → 3  
Output: 2 → 3
```

---

# 🚀 Approach: Dummy Node + Two Pointers

## 💡 Key Idea

Since the list is **sorted**, duplicates appear **next to each other**.

We use:

* `dummy` → helps handle edge cases (like duplicates at head)
* `prev` → last **valid (unique)** node
* `temp` → traverses the list

---

## ⚙️ Strategy

1. Create a dummy node and point it to head.
2. Traverse using `temp`.
3. If duplicates are found:

   * Skip all duplicate nodes
   * Connect `prev->next` to the next non-duplicate node
4. If current node is unique:

   * Move `prev` forward

---

## ✅ Correct Code

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* temp = head;

        while(temp != NULL){
            // Case 1: Duplicate found
            if(temp->next != NULL && temp->val == temp->next->val){
                
                // Skip all duplicates
                while(temp->next != NULL && temp->val == temp->next->val){
                    temp = temp->next;
                }

                prev->next = temp->next; // remove duplicates
            } 
            // Case 2: Unique node
            else {
                prev = temp; // move prev safely
            }

            temp = temp->next;
        }

        return dummy->next;
    }
};
```

---

## 🧠 Dry Run

### Input:

```text
1 → 2 → 3 → 3 → 4 → 4 → 5
```

### Steps:

* `1` → unique → keep
* `2` → unique → keep
* `3` → duplicate → skip all `3`s
* `4` → duplicate → skip all `4`s
* `5` → unique → keep

---

## ✅ Final Output

```text
1 → 2 → 5
```

---

## ⚠️ Important Notes

### ❌ Common Mistake

```cpp
prev = prev->next;
```

👉 This can break the list and cause wrong output.

### ✅ Correct Way

```cpp
prev = temp;
```

👉 Always move `prev` to a **valid confirmed node**

---

## 🏆 Why Use Dummy Node?

Without dummy:

* Hard to remove duplicates at the beginning

With dummy:

* Easy and safe pointer handling
* Works for all edge cases

---

## ⏱ Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`

---

## 🔥 Comparison

| Problem                         | Behavior              |
| ------------------------------- | --------------------- |
| Remove Duplicates (LeetCode 83) | Keep one copy         |
| Remove Duplicates II (This)     | Remove all duplicates |

---

## 🏁 Conclusion

* This is a classic **linked list + pointer manipulation** problem.
* Dummy node + careful pointer updates make the solution clean and efficient.
* Always ensure pointers never become invalid.

---

⭐ If this helped, consider starring your repo!
