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
 ListNode* NthNode(ListNode* head, int k){
    ListNode* temp=head;
    k=k-1;
    while(temp!=NULL){
        if(k==0) return temp;
        k--;
        temp=temp->next;
    }
    return temp;
 }
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        if(k % len == 0) return head;
        k = k % len;
        tail->next=head;
        ListNode* newnode = NthNode(head,len - k);
        head=newnode->next;
        newnode->next=NULL;
        return head;
    }
};