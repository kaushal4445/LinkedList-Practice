# 🔁 Remove Duplicates from Sorted Linked List (C++)

This repository explains an efficient approach to remove duplicates from a **sorted singly linked list**.

---

## 📌 Problem Statement

Given the `head` of a **sorted linked list**, delete all duplicates such that each element appears only once.

---

## 🧾 Example

```id="ex1"
Input: 1 → 1 → 2 → 3 → 3  
Output: 1 → 2 → 3
```

---

# 🚀 Approach: Two-Pointer Traversal

## 💡 Idea

Since the list is **already sorted**, duplicate elements will always be **adjacent**.

We use two pointers:

* `prev` → points to the last unique node
* `temp` → traverses the list

---

## 🧾 Code

```cpp id="code1"
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* prev = head;
        ListNode* temp = prev->next;

        while(temp != NULL){
            if(temp->val == prev->val){
                temp = temp->next;   // skip duplicate
                continue;
            }
            prev->next = temp;       // link unique node
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL; // remove leftover duplicates
        return head;
    }
};
```

---

## 🧠 Dry Run

```id="dry1"
Input: 1 → 1 → 2 → 3 → 3
```

### Step-by-step:

```id="dry2"
prev = 1, temp = 1 → duplicate → move temp  
prev = 1, temp = 2 → unique → link  
List: 1 → 2  

prev = 2, temp = 3 → unique → link  
List: 1 → 2 → 3  

prev = 3, temp = 3 → duplicate → skip  
```

### Final Result:

```id="dry3"
1 → 2 → 3
```

---

## ⚙️ How It Works

* If `temp->val == prev->val`
  👉 Duplicate → skip `temp`

* Else
  👉 Connect `prev->next = temp` and move both pointers

* At the end
  👉 `prev->next = NULL` ensures no leftover duplicate links

---

## ⏱ Complexity

* **Time:** `O(n)` (single traversal)
* **Space:** `O(1)` (no extra memory)

---

## 🏆 Advantages

* Efficient (one pass) ⚡
* No extra data structures needed
* Works in-place

---

## ⚠️ Important Edge Case

```id="edge1"
Input: NULL → Output: NULL
```

Handled by:

```cpp id="edge2"
if(head == NULL) return NULL;
```

---

# 📌 Alternative Simpler Approach (For Reference)

You can also solve this with just one pointer:

```cpp id="alt1"
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
```

---

# 🏁 Conclusion

* The sorted nature of the list makes duplicate removal straightforward.
* The **two-pointer approach** efficiently skips duplicates while maintaining structure.
* This is a common and important linked list pattern for interviews.

---

⭐ If you found this helpful, consider starring your repo!
