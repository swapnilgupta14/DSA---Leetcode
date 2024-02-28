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
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if( head == NULL || k==0){
//             return head;
//         }
//         ListNode *first = head;
//         ListNode *ptr = head;
//         ListNode *temp = head;
//         while (ptr->next != NULL){
//             ptr = ptr->next;
//         }
//         ptr->next = first;
//         while (k--){
//             temp = temp->next;
//         }
//         head = temp->next;
//         temp->next = NULL;
//         return head;
//     }
// };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }
        int length = 1; 
        ListNode* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
            length++;
        }
        ptr->next = head;
        k = k % length;
        int newTailPos = length - k;
        ptr = head;
        for (int i = 1; i < newTailPos; i++) {
            ptr = ptr->next;
        }
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
};
