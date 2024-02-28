/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if(head==NULL || head->next == NULL){
            return false;
        }
        while(fast != NULL && fast->next != NULL){
            
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast==slow){
                return true;
            }
        }
        return false;

    }
};