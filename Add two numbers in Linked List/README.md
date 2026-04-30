# ➕ Add Two Numbers (Linked List)

## 📖 Problem

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in **reverse order**, and each node contains a single digit.

Add the two numbers and return the sum as a linked list.

---

## 🧪 Example

```
Input:
l1 = 2 → 4 → 3   (represents 342)
l2 = 5 → 6 → 4   (represents 465)

Output:
7 → 0 → 8        (represents 807)
```

---

## 🚀 Approach: Digit-by-Digit Addition (Like Elementary Math)

### 💡 Idea

We simulate how we add numbers manually:

* Add digits from both lists
* Keep track of **carry**
* Create a new node for each digit of result

---

## 🔁 Algorithm

1. Create a **dummy node** (to simplify list construction)
2. Initialize `carry = 0`
3. Traverse both lists:

   * Add values from `l1`, `l2`, and `carry`
   * Compute:

     * `digit = sum % 10`
     * `carry = sum / 10`
   * Create a new node with `digit`
4. Continue until:

   * both lists खत्म AND carry = 0
5. Return `dummy->next`

---

## 🧠 Dry Run

```
  2 → 4 → 3
+ 5 → 6 → 4
------------
  7 → 0 → 8
```

Step-by-step:

* 2 + 5 = 7 → write 7
* 4 + 6 = 10 → write 0, carry 1
* 3 + 4 + 1 = 8 → write 8

---

## 💻 Code

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry) {
            int sum = 0;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;

            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }

        return dummy->next;
    }
};
```

---

## ⏱ Complexity

* **Time Complexity:** O(max(m, n))
* **Space Complexity:** O(max(m, n)) (for result list)

---

## ⚠️ Edge Cases

* Different length lists
  Example: 9 → 9 + 1 → Output: 0 → 0 → 1
* Final carry exists
* One list is empty

---

## 📊 Why Dummy Node?

Without dummy:

* You need extra checks for head

With dummy:

* Cleaner code
* No special handling for first node

---

## 📌 Key Insight

> Treat the linked list as a number in reverse and simulate addition with carry.

---

## 🎯 Conclusion

* Simple but powerful pattern
* Common in interviews
* Builds foundation for linked list manipulation

---

⭐ If you found this helpful, consider starring the repository!

