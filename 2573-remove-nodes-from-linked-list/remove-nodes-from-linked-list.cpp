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
 ListNode* reverse(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
       ListNode*newhead= reverse(head);
       ListNode* temp=newhead;
       ListNode* node=newhead;
       while(temp!=NULL){
        temp=temp->next;
        if(temp!=NULL&&temp->val>=node->val){
           node->next=temp;
           node=temp;
        }
       }
       node->next=NULL;
        ListNode* currhead=reverse(newhead);
        return currhead;
    }
};