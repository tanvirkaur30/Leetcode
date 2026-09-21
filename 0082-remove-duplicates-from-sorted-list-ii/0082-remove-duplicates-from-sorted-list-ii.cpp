/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* nextnode = temp->next;
            // Duplicate group found
            if (nextnode != NULL && temp->val == nextnode->val) {
                // Delete all nodes having the same value
                while (nextnode != NULL && temp->val == nextnode->val) {
                    ListNode* duplicate = nextnode;
                    nextnode = nextnode->next;
                    delete duplicate;
                }
                // Delete temp also
                delete temp;
                // Connect previous distinct node to next distinct node
                prev->next = nextnode;
                temp = nextnode;
            }
            else {
                // No duplicate
                prev = temp;
                temp = temp->next;
            }
        }
        return dummy.next;
    }
};