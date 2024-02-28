/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int l1=0;
//         int l2=0;
//         ListNode *first = headA;
//         ListNode *sec = headB;
//         while(first->next != NULL){
//             first = first->next;
//             l1++;
//         }
//         while(sec->next != NULL){
//             sec = sec->next;
//             l2++;
//         }
//         first = headA;
//         sec = headB;
//         if(l2>l1){
//             int leng2 = l2-l1;
//             while (leng2--){
//                 sec = sec->next;
//             }
//         }
//         if(l1>l2){
//             int leng1 = l1-l2;
//             while (leng1--){
//                 first = first->next;
//             }
//         }
//         if(l1==l2){
//             while(first!= NULL and sec!=NULL){
//                 if(first == sec){
//                     return sec;
//                 }
//                 first=first->next;
//             sec=sec->next;

//             }
//                 return NULL;
            
//         }
//         while (first->next != NULL && sec->next != NULL){
//             if (first == sec){
//                 return sec;
//             }
//             first=first->next;
//             sec=sec->next;
//         }
//         return NULL;
//     }
// };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        int l1 = 0, l2 = 0;
        ListNode *curA = headA, *curB = headB;
        while (curA) {
            l1++;
            curA = curA->next;
        }

        while (curB) {
            l2++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (l1 > l2) {
            int diff = l1 - l2;
            while (diff--) {
                curA = curA->next;
            }
        } else if (l2 > l1) {
            int diff = l2 - l1;
            while (diff--) {
                curB = curB->next;
            }
        }
        while (curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }

        return curA;
    }
};
