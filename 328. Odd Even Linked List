/* *********************************************** *
 *      Annie Wang 2016.11.25                      *
 * Idea: go through the linked list and seperate   *
 *      the list into 2 lists in order, which      *
 *      represents odd and even respectively       *
 * Remark: always break the chain when the whole   *
 *      list is sorted                             *
 * *********************************************** *
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
    ListNode* oddEvenList(ListNode* head) {
        // define odd and even chain
        ListNode *odd = new ListNode(0);
        ListNode *even = new ListNode(0);
        // define cursors
        ListNode *oddc = odd;
        ListNode *evenc = even;
        ListNode *c = head;
        bool isOdd = true;
        
        while(c){
            // cout << c->val << endl;
            if( isOdd ){
                oddc->next = c;
                oddc = oddc->next;
                isOdd = false;
            } else{
                evenc->next = c;
                evenc = evenc->next;
                isOdd = true;
            }
            c = c->next;
        }
        evenc->next = NULL;
        oddc->next = even->next;
        return odd->next;
    }
};
