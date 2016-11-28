/* ********************************** *
 *      Annie Wang 2016.11.27         *
 * Idea: incrementing n - 1 elements  *
 *      by 1 is equal to one element  *
 *      minus 1                       *
 * Remark: too simple to have remark  *
 * ********************************** *
 */
        
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;
        int min = nums[0];
        for(int i = 1; i < len; i++){
            if(nums[i] < min){
                min = nums[i];
            }
        }
        int opt = 0;
        for(int i = 0; i < len; i++){
            opt += nums[i] - min;
        }
        return opt;
        
    }
};
