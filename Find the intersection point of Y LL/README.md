# 🔗 Intersection of Two Linked Lists

## 📖 Problem

Given the heads of two singly linked lists, return the node at which the two lists intersect.
If the two linked lists have no intersection, return `NULL`.

---

## 🧪 Example

```
List A: 1 → 2 → 3 \
                      → 7 → 8 → 9
List B:       4 → 5 /
```

### ✅ Output:

```
7 (Intersection Node)
```

---

## 🚀 Approach: Two Pointer Technique (Optimal)

### 💡 Idea

We use **two pointers**:

* `temp1` starts from `headA`
* `temp2` starts from `headB`

### 🔁 Trick:

When a pointer reaches the end of a list, **redirect it to the other list's head**.

---

## 🧠 Why This Works

* Suppose:

  * Length of List A = `m`
  * Length of List B = `n`
* After switching heads:

  * Both pointers travel **m + n distance**
* So they will meet at:

  * Intersection node ✅
  * OR `NULL` (if no intersection)

---

## 🔄 Visualization

```
temp1: A → B
temp2: B → A
```

They sync up after switching paths.

---

## 💻 Code

```cpp
class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 != temp2) {
            temp1 = (temp1 == NULL) ? headB : temp1->next;
            temp2 = (temp2 == NULL) ? headA : temp2->next;
        }

        return temp1; // or temp2 (both are same here)
    }
};
```

---

## ⏱ Complexity

* **Time Complexity:** O(m + n)
* **Space Complexity:** O(1) (No extra space used)

---

## ⚠️ Edge Cases

* No intersection → returns `NULL`
* One list is empty
* Both lists are same
* Intersection at head

---

## 📊 Comparison with Other Methods

| Approach           | Time   | Space | Notes       |
| ------------------ | ------ | ----- | ----------- |
| Brute Force        | O(m*n) | O(1)  | Slow        |
| Hashing            | O(m+n) | O(n)  | Extra space |
| Two Pointer (This) | O(m+n) | O(1)  | ✅ Optimal   |

---

## 📌 Key Insight

> By switching heads, both pointers cover equal distance, eliminating length difference.

---

## 🎯 Conclusion

* Elegant and optimal solution
* No need to calculate lengths
* Works in one pass

---

⭐ If you found this helpful, consider starring the repository!
