/* ************************************************** *
 *      Annie Wang 2016.11.27                         *
 * Idea：enhanced brute force, but beats 88.86% other *
 *      submissions on LeetCode \(^o^)/               *
 * Remark：be careful with iterators                  *
 * ************************************************** *
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int x = 0;
        int reached = x + nums[x];
        int len = nums.size() - 1;
        int count = 0;
        if(len < 1) return count;
        
        while( x < len ){
            if( reached >= len ){
                count++;
                x = len;
            } else {
                int next = x + 1;
                int bound = reached;
                for(int i = next; i <= bound; i++){
                    if( i + nums[i] > reached ){
                        reached = i + nums[i];
                        next = i;
                    }
                }
                x = next;
                count++;
            }
        }
        return count;
    }
};