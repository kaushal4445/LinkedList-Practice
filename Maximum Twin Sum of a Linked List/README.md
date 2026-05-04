# 🔗 Maximum Twin Sum of a Linked List

## 📌 Problem

Given a singly linked list of even length, find the **maximum twin sum**.

* The twin of the `i-th` node is the `(n - i - 1)-th` node.
* Return the **maximum sum** of such pairs.

---

## 💡 Approach (Simple & Efficient)

### ✅ Idea:

1. Traverse the linked list and store values in a vector.
2. Use **two pointers**:

   * `i` → start
   * `j` → end
3. Calculate pair sum:

   ```
   ans[i] + ans[j]
   ```
4. Keep track of the **maximum sum**.

---

## ⚙️ Algorithm Steps

1. Traverse linked list → store elements in `vector<int>`
2. Initialize:

   * `i = 0`
   * `j = n - 1`
3. Loop while `i < j`:

   * Calculate sum
   * Update maximum
   * Move pointers inward
4. Return result

---

## 🚀 Code Implementation (C++)

```cpp
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;

        // Store values in vector
        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        // Two pointer approach
        int result = 0;
        int i = 0;
        int j = ans.size() - 1;

        while(i < j){
            result = max(result, ans[i] + ans[j]);
            i++;
            j--;
        }

        return result;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

---

## 🔍 Example

### Input:

```
1 → 2 → 3 → 4
```

### Twin Pairs:

```
(1,4) → 5
(2,3) → 5
```

### Output:

```
5
```

---

## 🧠 Key Insight

Instead of modifying the linked list:

* Convert it into an array
* Apply the **two-pointer technique**

This keeps the solution simple and easy to understand.

---

## 📂 Repository Structure

```
Maximum-Twin-Sum/
│── README.md
│── solution.cpp
```
