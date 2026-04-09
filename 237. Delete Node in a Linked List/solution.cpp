void deleteNode(ListNode* &head, int value) {
    if (!head) return;

    if (head->val == value) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode* curr = head;
    while (curr->next && curr->next->val != value) {
        curr = curr->next;
    }
    if (curr->next) {
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
}
