/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        Node* copyHead = head->next;
        while (curr != NULL) {
            Node* copy = curr->next;
            curr->next = copy->next;
            if (copy->next != NULL)
                copy->next = copy->next->next;
            curr = curr->next;
        }
        return copyHead;
    }
};