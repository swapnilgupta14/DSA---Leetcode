class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev_group_end = dummy;
        ListNode* curr_group_start = head;
        
        int length = 0;
        ListNode* temp = head;
        
        // Calculate the length of the linked list
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        
        while (length >= k) {
            ListNode* group_start = curr_group_start;
            ListNode* group_end = prev_group_end->next;
            
            for (int i = 1; i < k; i++) {
                ListNode* temp = group_end->next;
                group_end->next = temp->next;
                temp->next = group_start;
                prev_group_end->next = temp;
                group_start = temp;
            }
            
            prev_group_end = curr_group_start;
            curr_group_start = group_end->next;
            length -= k;
        }
        
        return dummy->next;
    }
};
