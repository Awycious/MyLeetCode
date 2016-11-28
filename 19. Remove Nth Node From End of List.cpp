
/* ********************************************************* *
 *      Annie Wang 2016.11.19                                *
 * Idea: simple problem, idea shown in comments              *
 * Remark: as found in discussion, there is an idea using 2  *
 *          pass, one goes n steps forward, then             *
 *          count the 2 pointers together until one is NULL. *
 *          This method sounds smarter, however total steps  *
 *          is n + 2 * (length - n) = 2 * length - n,        *
 *          exactly same as mine, I don't think the runtime  *
 *          will be different.                               *
 * ********************************************************* *
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode * mine = head;
        
        // count the length
        while(mine){
            len++;
            mine = mine->next;
        }
        // calculate the deleting node
        len -= n;
        
        // delete the node
        mine = new ListNode(0);
        ListNode *mine2 = mine;
        mine->next = head;
        
        for(int i = 0; i < len; i++){
            mine = mine->next;
        }
        mine->next = mine->next->next;
        
        // return
        return mine2->next;
        
    }
};
