/* ********************************************* *
 *      Annie Wang 2016.11.30                    *
 *  Idea: simple                                 *
 *  Remark: N/A                                  *
 * ********************************************* *
 */
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * n = head->next;
        head->next = NULL;
        ListNode * opt = head;
        
        while(n){
            ListNode * nn = n->next;
            n->next = opt;
            opt = n;
            n = nn;
        }
        return opt;
    }
};
