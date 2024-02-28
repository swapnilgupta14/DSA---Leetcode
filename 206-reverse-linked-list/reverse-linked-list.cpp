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
    ListNode* reverseList(ListNode* head) {
        
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode *curr = head;
        ListNode *first = head;
        ListNode *after = curr->next;
        ListNode *temp =NULL;
        while(after != NULL){
            temp = after->next;
            after->next = curr;
            curr = after;
            after = temp;
        }
        first->next = NULL;
        head = curr;
        return head;
    }
};