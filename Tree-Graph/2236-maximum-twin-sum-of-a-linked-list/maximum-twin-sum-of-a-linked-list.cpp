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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        int i =1;
        int half = (count/2);
        int max_sum = 0;
        stack <int> st;
        temp = head;
        if(count == 2) return head->val + head->next->val;
        while(i <= count && temp!=NULL){
            if(i <= half) st.push(temp->val);
            else{
                cout << st.top() << "\n";
                int sum = st.top() + temp->val;
                if (sum> max_sum) max_sum = sum;
                st.pop();
            }
            cout << temp->val << endl;
            temp = temp->next;
            i++;
            cout << "\n";
        }
        return max_sum;
    }

private: 
    // brute solution - TLE
    int function(ListNode* node, int i, int count){
        ListNode* ptr = node;
        int dis = count - i;
        while(dis) {
            ptr = ptr->next;
            dis--;
        }
        return ptr->val + node->val;
    }
    int pairSum1(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        temp = head;
        int i =1;
        int half = (count/2);
        int max_sum = 0;
        while(i <= half && count > half && temp != NULL){
            int su_m = function(temp, i, count);
            if(su_m > max_sum) max_sum = su_m;
            i++;
            count --;
            temp = temp->next;
        }
        return max_sum;
    }
};