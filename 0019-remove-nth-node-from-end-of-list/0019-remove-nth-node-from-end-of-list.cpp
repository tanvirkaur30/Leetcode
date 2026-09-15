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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count =0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(n==count) return head->next;
        temp=head;
        int res= count-n;
        while(temp!=NULL){
            res--;
            if(res==0) break;
            temp=temp->next;
        }
        ListNode* delnode = temp->next;
        temp->next=temp->next->next;
        delete delnode;
        return head;
    }
};