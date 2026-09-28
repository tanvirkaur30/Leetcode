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
ListNode* findmiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* mergelists(ListNode* list1,ListNode* list2){
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
            temp->next = list1;
            list1=list1->next;
        }
        else{
            temp->next = list2;
            list2=list2->next;
        }
        temp=temp->next;
    }
    if(list1) temp->next = list1;
    else temp->next = list2;
    return dummy->next;
}
class Solution {
public:
    ListNode* sortList(ListNode* head) {
       if(head==NULL || head->next ==NULL) return head;
       ListNode* middle = findmiddle(head);
       ListNode* secondhead = middle->next;
       middle->next =NULL;
       ListNode* left = sortList(head);
       ListNode* right = sortList(secondhead);
       return mergelists(left,right);
    }
};