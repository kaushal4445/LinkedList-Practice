# 🧩 Minimum Pair Removal to Make Array Sorted

## 📌 Problem

Given an array `nums`, you can perform the following operation:

👉 Choose **adjacent pair with minimum sum**, merge them into one element (sum), and remove one index.

Your task is to find the **minimum number of operations** required to make the array **sorted (non-decreasing)**.

---

## 💡 Approach (Simple & Clear)

### 🔹 Core Idea:

* Repeatedly merge the **adjacent pair with the smallest sum**
* Continue until the array becomes **sorted**

---

## ⚙️ Step-by-Step

1. Check if array is already sorted → if yes, return 0
2. Find the **adjacent pair with minimum sum**
3. Merge them:

   * Replace first element with sum
   * Remove second element
4. Count operation
5. Repeat until array becomes sorted

---

## 🧠 Key Insight

👉 Merging the **smallest pair first** helps reduce disorder gradually
👉 Greedy approach works effectively here

---

## 🧪 Example

### Input:

```text id="ex1"
nums = [5, 2, 3, 1]
```

### Process:

```text id="ex2"
Step 1: (2+3)=5 → [5, 5, 1]
Step 2: (5+1)=6 → [5, 6]
Now sorted
```

### Output:

```text id="ex3"
Operations = 2
```

---

## 🔍 Dry Run

```text id="ex4"
nums = [4, 1, 3, 2]

Pairs:
(4+1)=5
(1+3)=4 ← minimum
(3+2)=5

Merge → [4, 4, 2]

Repeat...
```

---

## 🚀 Code (C++)

```cpp id="code1"
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int minSum = INT_MAX;
        int index = -1;

        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] + nums[i+1] < minSum) {
                index = i;
                minSum = nums[i] + nums[i+1];
            }
        }
        return index;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while(!is_sorted(begin(nums), end(nums))) {
            int index = minPairSum(nums);

            nums[index] = nums[index] + nums[index+1];

            nums.erase(begin(nums) + index + 1);

            operations++;
        }

        return operations;
    }
};
```

---

## ⚡ Complexity

* **Time Complexity:** `O(n^2 log n)` (due to repeated sorting check + traversal)
* **Space Complexity:** `O(1)`

---

## 🎯 Key Points

* Greedy: always merge **minimum adjacent pair**
* Use `is_sorted()` to check stopping condition
* Array size reduces after every operation
* Careful with index handling after erase

---

## ✅ Summary

👉 Find smallest adjacent pair
👉 Merge it
👉 Repeat until sorted

✔ Greedy approach
✔ Easy to implement
✔ Good for interviews

---

