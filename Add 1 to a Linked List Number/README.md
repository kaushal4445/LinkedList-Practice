# ➕ Add One to a Number Represented by Linked List

## 📖 Problem

Given a linked list where each node represents a digit of a number, add **1** to the number and return the updated list.

### Example:

Input:
1 → 9 → 9

Output:
2 → 0 → 0

---

## 🚀 Approaches

### 1️⃣ Recursive Approach (Elegant)

### 💡 Idea:

* Traverse to the **last node using recursion**
* Add `1` at the end
* Propagate carry backwards

---

### 🔁 Algorithm:

1. Go till last node (`temp == NULL`)
2. Return carry = 1
3. Add carry to current node
4. If value < 10 → stop carry
5. Else → set node to 0 and carry = 1

---

### 🧠 Code:

```cpp
class Solution {
public:

    int helperFunction(Node* temp) {
        if (temp == NULL) {
            return 1;
        }

        int carry = helperFunction(temp->next);

        temp->data = temp->data + carry;

        if (temp->data < 10) {
            return 0;
        } else {
            temp->data = 0;
            return 1;
        }
    }

    Node* addOne(Node* head) {
        int carry = helperFunction(head);

        if (carry == 1) {
            Node* newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }

        return head;
    }
};
```

---

### ⏱ Complexity:

* Time: O(n)
* Space: O(n) (recursion stack)

---

## 2️⃣ Iterative Approach (Reverse Method)

### 💡 Idea:

* Reverse the list
* Add 1 like normal addition
* Reverse back

---

### 🧠 Code:

```cpp
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addOne(Node* head) {
    head = reverse(head);

    Node* temp = head;
    int carry = 1;

    while (temp != NULL) {
        temp->data += carry;

        if (temp->data < 10) {
            carry = 0;
            break;
        }

        temp->data = 0;
        carry = 1;

        if (temp->next == NULL && carry == 1) {
            temp->next = new Node(1);
            carry = 0;
            break;
        }

        temp = temp->next;
    }

    return reverse(head);
}
```

---

### ⏱ Complexity:

* Time: O(n)
* Space: O(1)

---

## 📊 Comparison

| Approach  | Space | Cleanliness | Preferred  |
| --------- | ----- | ----------- | ---------- |
| Recursive | O(n)  | ⭐⭐⭐⭐        | Interview  |
| Iterative | O(1)  | ⭐⭐⭐         | Production |

---

## 🧪 Edge Cases

* 9 → 9 → 9 → Output: 1 → 0 → 0 → 0
* 0 → Output: 1
* Single node

---

## 📌 Conclusion

* Use **recursion for clarity**
* Use **iteration for efficiency**

---
