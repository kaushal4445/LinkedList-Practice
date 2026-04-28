📌 Remove N-th Node From End of Linked List (C++)
🧠 Problem

Given the head of a singly linked list, remove the n-th node from the end and return the updated list.

💡 Intuition

Instead of counting the total length first, we use a two-pointer technique:

Move one pointer (fast) ahead by n steps
Then move both fast and slow together
When fast reaches the end, slow will be just before the node to delete
🚀 Approach (Step-by-Step)
1️⃣ Initialize pointers
ListNode* fast = head;
ListNode* slow = head;

2️⃣ Move fast n steps ahead
for(int i = 0; i < n; i++){
    fast = fast->next;
}

3️⃣ Handle Edge Case (Delete Head)
if(fast == NULL){
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}

🔥 Why this is needed?

If fast becomes NULL, it means:

n == length of linked list


👉 So the node to delete is the first node (head)

4️⃣ Move both pointers
while(fast->next != NULL){
    fast = fast->next;
    slow = slow->next;
}


👉 Now:

fast → last node
slow → just before node to delete
5️⃣ Delete the node
ListNode* deleteNode = slow->next;
slow->next = slow->next->next;
delete deleteNode;

6️⃣ Return result
return head;

✅ Full Working Code
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;

        // Step 1: Move fast n steps
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        // Step 2: If fast is NULL → delete head
        if(fast == NULL){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Step 3: Move both pointers
        ListNode* slow = head;
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        // Step 4: Delete node
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;

        return head;
    }
};

🧪 Example Dry Run
Input:
1 → 2 → 3 → 4 → 5
n = 2

Step-by-step:
Move fast 2 steps → points to 3

Move both pointers:

fast → 5
slow → 3

Delete slow->next → node 4
Output:
1 → 2 → 3 → 5

⚠️ Edge Cases
Case	Explanation
n = 1	delete last node
n = length	delete head
single node	list becomes empty
⏱️ Complexity
Time: O(n)
Space: O(1)
🔥 Best Approach (Dummy Node – Recommended)

This avoids edge cases completely:

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for(int i = 0; i <= n; i++){
            fast = fast->next;
        }

        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;

        return dummy->next;
    }
};
