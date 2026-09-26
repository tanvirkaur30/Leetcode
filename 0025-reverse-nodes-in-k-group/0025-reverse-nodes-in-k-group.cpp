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
       ListNode* temp=head;//temp will be the beginning of the current group
       ListNode* nextofkthnode=NULL;//stores the first node of the next group before we cut the current 
       ListNode* prevlast=NULL;//stores last node of previously reversed group
       while(temp!=NULL){
        ListNode* kthnode = getkthNode(temp,k);//get kth node using temp not head 
        if(kthnode==NULL){ //if no kthnode exists that means we have to connect the node as it is 
            if(prevlast) prevlast->next=temp;
            break;
        }
        nextofkthnode=kthnode->next;//save beginning of the next group
        kthnode->next=NULL;//cut the current group
        reverseLL(temp);  //reverse it 
        if(temp==head){  //if its the first group then head needs to be updated
            head=kthnode;
        }else{                     // if its the group after first group,
            prevlast->next=kthnode; //connect the last node of previous group with first of next
        }
        prevlast=temp; // temp was the original first node, after reversal it becomes the LAST node.
        temp=nextofkthnode;//move temp to the beginning of the next group
       }
       return head;
    }
};