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
    ListNode* removeElements(ListNode* head, int val) {
       ListNode* temp=head;
       ListNode* prev =NULL;
       ListNode* nextnode=NULL;
       while(temp!=NULL){
        if(temp->val==val){
            if(temp==head){
                head=head->next;
            }
           nextnode=temp->next;
           if(prev) prev->next=temp->next;   
            delete temp;
            temp=nextnode;
            continue;
        }
        prev=temp;
        temp=temp->next;
       }
       return head;
    }
    
};

/*while(temp != NULL){
    if(temp->val == val){
        prev->next = temp->next;
        delete temp;
        temp = prev->next;
        continue; //I deleted this node, so skip the remaining statements and start the next iteration.
    }
    prev = temp;
    temp = temp->next;
}*/