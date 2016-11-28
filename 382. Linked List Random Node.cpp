/* ************************************************************************************** *
 *              Annie Wang 2016.11.28                                                     *
 *  Idea: randomly chosen a number                                                        *
 *  Remark: how come this is a medium level? No remark....                                *
 * ************************************************************************************** *
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
private:
    int len = 0;
    ListNode *myHead;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        len = 0;
        myHead = head;
        ListNode *opt = myHead;
        while(opt){
            len++;
            opt = opt->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int myrand = rand() % len;
        ListNode *opt = myHead;
        while(myrand > 0){
            myrand--;
            opt = opt->next;
        }
        return opt->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
