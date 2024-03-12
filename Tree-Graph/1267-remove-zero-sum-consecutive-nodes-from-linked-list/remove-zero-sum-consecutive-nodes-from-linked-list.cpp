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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        std::unordered_map<int, ListNode*> mapSum;
        int sum = 0;
        while (current != nullptr) {
            sum += current->val;
            mapSum[sum] = current;
            current = current->next;
        }
        sum = 0;
        current = dummy;
        while (current != nullptr) {
            sum += current->val;
            current->next = mapSum[sum]->next;
            current = current->next;
        }
        return dummy->next;
    }
};