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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode *ptr = head;
        int count = 0;
        while(ptr != NULL){
            count +=1;
            ptr = ptr->next;
        }
        ptr = head;
        // dis -= 2;
        count = count/2;
        // cout << count << dis;
        while(count > 0){
            ptr = ptr->next;
            count-=1;
        }
        // cout << ptr->val;
        return ptr;
    }
};