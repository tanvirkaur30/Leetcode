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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* prevleft=dummy;
        for(int i = 0;i<left-1;i++){
            prevleft= prevleft->next;
        }
        ListNode* curr=prevleft->next;
        ListNode* prev = NULL;
        for(int i=0;i<right-left+1;i++){
            ListNode* front = curr->next;
            curr->next = prev;
            prev=curr;
            curr=front;
        }
        ListNode* leftnode = prevleft->next;
        prevleft->next = prev;
        leftnode->next = curr;
        return dummy->next ;
    }
};