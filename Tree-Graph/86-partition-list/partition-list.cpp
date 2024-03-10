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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* small = NULL;
        ListNode* large = NULL;
        ListNode* firstSmall = NULL;
        ListNode* firstLarge = NULL;
        while (head != NULL) {
            ListNode* nextNode = head->next;
            if (head->val < x) {
                if (small == NULL) {
                    small = head;
                    firstSmall = small;
                } else {
                    small->next = head;
                    small = small->next;
                }
            } else {
                if (large == NULL) {
                    large = head;
                    firstLarge = large;
                } else {
                    large->next = head;
                    large = large->next;
                }
            }
            head->next = NULL;
            head = nextNode;
        }
        if (firstSmall != NULL) {
            small->next = firstLarge;
            return firstSmall;
        } else {
            return firstLarge;
        }
    }
};
