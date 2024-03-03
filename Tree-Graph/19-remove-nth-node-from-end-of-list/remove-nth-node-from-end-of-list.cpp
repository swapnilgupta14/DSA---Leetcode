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
        ListNode* temp = head;
        int count=0;
        while(temp != nullptr){
            count +=1;
            temp = temp->next;
        }
        temp = head;
        // cout << count;
        if(count == n){
            temp = head->next;
            head->next = NULL;
            head = temp;
            return head;
        }
        int distance = count - n;
        while (distance){
            if(distance == 1){
            if(temp->next->next == nullptr){
                temp->next = NULL;
                return head;
            }else{
                ListNode* link = temp->next->next;
                temp->next->next = NULL;
                temp ->next = link;
                return head;
            }}
            distance -=1;
            temp = temp->next;
        }
        return head;
    }
};