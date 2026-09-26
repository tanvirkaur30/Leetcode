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
 ListNode* getkthNode(ListNode* head,int k){ //function to get kth node in the LL
    ListNode* temp=head;
    k=k-1;
    while(temp!=NULL && k!=0){
        k--;
        temp=temp->next;
    }
    return temp;
 }
 ListNode* reverseLL(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* temp=head;
    ListNode* prev = NULL;
    while(temp!=NULL){
        ListNode* front=temp->next;
        temp->next=prev;
        prev =temp;
        temp=front;
    }
    return prev ;
 }
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* temp=head;
       ListNode* nextofkthnode=NULL;
       ListNode* prevlast=NULL;
       while(temp!=NULL){
        ListNode* kthnode=getkthNode(temp,k);
        if(kthnode==NULL){
           if(prevlast) prevlast->next=temp;
            break;
        }
       nextofkthnode=kthnode->next;
        kthnode->next=NULL;
        reverseLL(temp);
        if(head==temp){
            head=kthnode;
        }else{
           prevlast->next=kthnode;
        }
        prevlast=temp;
        temp=nextofkthnode;

       }
       return head;
    }
};