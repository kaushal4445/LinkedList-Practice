class Solution {
public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp = *head_ref;

        while (temp != NULL) {
            if (temp->data == x) {
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;

                // If node is head
                if (temp == *head_ref) {
                    *head_ref = temp->next;
                }

                // Update next node's prev
                if (nextNode != NULL) {
                    nextNode->prev = prevNode;
                }

                // Update prev node's next
                if (prevNode != NULL) {
                    prevNode->next = nextNode;
                }

                delete temp;
                temp = nextNode;
            } else {
                temp = temp->next;
            }
        }
    }
};
