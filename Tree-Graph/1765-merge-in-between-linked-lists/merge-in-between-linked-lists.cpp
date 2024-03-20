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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr11 = list1;
        // ListNode* ptr12 = list1;
        int diff = abs(b-a) + 1;
        while(a -1){
            ptr11 = ptr11->next;
            a-=1;
        }
        ListNode* ptr12 = ptr11;
        while(diff){
            ptr12 = ptr12->next;
            diff-=1;
        }
        ListNode* temp = ptr12;
        ptr12 = ptr12->next;
        temp -> next = NULL;
        cout << ptr11->val << " " << ptr12->val << endl;
        ListNode* ptr2 = list2;
        while(ptr2->next != NULL){
            ptr2 = ptr2->next;
        }
        ptr11->next = list2;
        ptr2->next = ptr12;
        cout << ptr2 ->val;
        return list1;
    }
};