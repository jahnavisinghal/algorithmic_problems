/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) {
            return NULL;
        }
        ListNode* ptrSlow = head;
        ListNode* ptrFast = head;
        bool first = true;
        while(ptrFast && (ptrFast!=ptrSlow||first)) {
            first = false;
            ptrSlow = ptrSlow->next;
            if(!ptrFast->next) {
                break;
            }
            ptrFast = ptrFast->next->next;
        }
        if(!ptrFast || !ptrFast->next) {
            return NULL;
        }
        ptrFast = head;
        while(ptrFast!=ptrSlow) {
            ptrFast = ptrFast->next;
            ptrSlow = ptrSlow->next;
        }
        return ptrSlow;
    }
};
