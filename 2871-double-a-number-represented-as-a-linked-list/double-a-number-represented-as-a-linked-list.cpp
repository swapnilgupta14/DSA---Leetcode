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
private:
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
public:
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        ListNode* newHead = reverse(head);
        ListNode* temp1 = newHead;
        ListNode* temp = newHead;

        while(temp != nullptr){
            int m = temp->val * 2 + carry;
            if(m > 9){
                int rem = m % 10;
                temp->val  = rem;
                carry = 1;
            }else {
                carry = 0;
                temp->val = m;
            }
            temp = temp->next;
        }

        // while(temp1 != nullptr){
        //     cout << temp1 -> val << " ";
        //     temp1 = temp1->next;
        // }

        ListNode* again = reverse(newHead);

        if(carry == 1){
            ListNode* beforeAgain = new ListNode();
            beforeAgain->val = 1;
            beforeAgain->next = again;
            return beforeAgain;
        }else{
            return again;
        }
    }
};