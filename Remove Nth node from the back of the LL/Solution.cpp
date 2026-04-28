#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor for Node with data and next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor for Node with only data (next = nullptr)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Class to hold the solution logic
class Solution {
public:
    // Function to print the linked list
    void printLL(Node* head) {
        while (head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }

    // Function to delete the Nth node from the end 
    // using the optimized two-pointer method
    Node* deleteNthNodeFromEnd(Node* head, int N) {
        // Create a dummy node before head to handle edge cases
       ListNode* fast = head;
        for(int i =0; i<n; i++){
            fast = fast->next;
        }
          // If fast is NULL → delete head
        if(fast == NULL){
            // ListNode* temp = head;
            // head = head->next;
            // delete temp;
            // return head;

            return head->next;
        }

        ListNode* slow = head;

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;

        delete(deleteNode);

        return head;
    }
};

// Main driver code
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;

    // Create linked list manually
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Create Solution object
    Solution sol;

    // Delete the Nth node from the end
    head = sol.deleteNthNodeFromEnd(head, N);

    // Print the modified linked list
    sol.printLL(head);
}
