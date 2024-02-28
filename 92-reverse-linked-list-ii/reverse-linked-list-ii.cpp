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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* leftNode = prev->next;
        ListNode* current = leftNode->next;

        for (int i = left; i < right; i++) {
            leftNode->next = current->next;
            current->next = prev->next;
            prev->next = current;
            current = leftNode->next;
        }

        return dummy->next; 
    }   
};

ListNode* reverse(ListNode* first,  ListNode* second){
        ListNode *left = first;
        ListNode *right = left->next;
        ListNode *temp = NULL;
        while (right->next != second){
            temp = right->next; 
            right->next = left;
            left = right;
            right= temp;
        }
        return first;
    }