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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * help = head->next;
        head->next = swapPairs(head->next->next);
        help->next = head;
        return help;
    }
};

/* ************************************************ *
 *      Annie Wang 2016.11.21                       *
 *  Idea: recursion                                 *
 *  Remark: NULL                                    *
 * ************************************************ *
 */
