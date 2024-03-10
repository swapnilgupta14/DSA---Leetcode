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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp = head->next;
        while(odd->next->next != NULL || even->next->next != NULL){
            // cout << odd->val << ", " << even->val;
            if(odd->next !=NULL && odd->next->next != NULL){
                cout << odd->val;
                odd->next = odd->next->next;
                odd = odd->next;
                cout << " ka next ->" << odd->val << endl;
            }
            if(even->next !=NULL && even->next->next != NULL) {
                // cout << "even";
                cout << even->val;
                even->next = even->next->next;
                even = even->next;
                cout << " ka next ->" << even->val << endl;

            }
            if(odd == NULL || even == NULL || odd->next== NULL || even->next == NULL) break;
        }
        even->next = NULL;
        odd->next = temp;
        return head;

    }
};