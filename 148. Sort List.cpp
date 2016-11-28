/* ************************************************** *
 *      Annie Wang 2016.11.24                         *
 * Idea: typical merge sort                           *
 * Remark: N/A                                        *
 * ************************************************** *
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
    // calculate length
    int length(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    // return mid point and seperate the chain into 2
    ListNode* midPoint(ListNode* head){
        int mid = length(head) / 2 - 1;
        while(mid > 0){
            head = head->next;
            mid--;
        }
        ListNode * opt = head->next;
        head->next = NULL; 
        return opt;
    }
    // merge two list and return the head node
    ListNode* merge(ListNode * l, ListNode * r){
        ListNode *opt = new ListNode(0);
        ListNode *cursor = opt;
        
        while( l && r ){
            int a = l->val;
            int b = r->val;
            if( a < b ){
                cursor->next = l;
                l = l->next;
                cursor = cursor->next;
            } else {
                cursor->next = r;
                r = r->next;
                cursor = cursor->next;
            }
        }
        if( l ) cursor->next = l;
        else cursor->next = r;
        return opt->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        // merge sort
        if(!head || !(head->next)) return head;
        ListNode * mid = midPoint( head );
        return merge( sortList( mid ), sortList( head ) );
    }
};
