# 🔢 Convert Binary Linked List to Decimal (C++)

This repository explains **two approaches** to solve the problem:

> Given a singly linked list where each node contains `0` or `1`, return its **decimal value**.

---

## 📌 Problem Example

```
Input: 1 → 0 → 1
Output: 5
Explanation: (101)_2 = (5)_10
```

---

# 🚀 Approach 1: Reverse Linked List + Power Calculation

## 💡 Idea

1. Reverse the linked list.
2. Traverse from least significant bit (LSB).
3. Add `2^power` whenever node value is `1`.

---

## 🧾 Code

```cpp
ListNode* reverseLL(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* last = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        head = reverseLL(head);
        
        int result = 0;
        int power = 0;

        while(head != NULL){
            if(head->val == 1){
                result += pow(2, power);
            }
            power++;
            head = head->next;
        }

        return result;
    }
};
```

---

## 🧠 Dry Run

```
Input: 1 → 0 → 1

Step 1: Reverse → 1 → 0 → 1 (same here, but logic applies generally)

Step 2:
power = 0 → 1 * 2^0 = 1
power = 1 → 0 * 2^1 = 0
power = 2 → 1 * 2^2 = 4

Result = 1 + 0 + 4 = 5
```

---

## ⏱ Complexity

* Time: `O(n)` (reverse + traversal)
* Space: `O(n)` (recursion stack)

---

## ⚠️ Drawbacks

* Uses recursion → extra stack space
* Uses `pow()` → slower
* Requires reversing the list

---

# ⚡ Approach 2: Efficient (Without Reversing)

## 💡 Idea

Treat it like building a binary number:

```
result = result * 2 + current_bit
```

---

## 🧾 Code

```cpp
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;

        while(head != NULL) {
            result = result * 2 + head->val;
            head = head->next;
        }

        return result;
    }
};
```

---

## 🧠 Dry Run

```
Input: 1 → 0 → 1

Step 1: result = 0*2 + 1 = 1  
Step 2: result = 1*2 + 0 = 2  
Step 3: result = 2*2 + 1 = 5  

Final Answer = 5
```

---

## ⏱ Complexity

* Time: `O(n)`
* Space: `O(1)` ✅

---

## 🏆 Why Approach 2 is Better

| Feature        | Approach 1 ❌ | Approach 2 ✅ |
| -------------- | ------------ | ------------ |
| Reverse Needed | Yes          | No           |
| Extra Space    | O(n)         | O(1)         |
| Simplicity     | Medium       | Easy         |
| Performance    | Slower       | Faster       |

---

# 📌 Final Recommendation

👉 Always prefer **Approach 2 (Iterative)**
It is:

* Cleaner ✨
* Faster ⚡
* Memory efficient 💡

---

# 🏁 Conclusion

This problem demonstrates how binary numbers can be processed efficiently using simple arithmetic instead of extra operations like reversing.

---

⭐ If you found this helpful, consider starring the repo!
