/* *************************************************** *
 *      Annie Wang 2016.11.28                          *
 *  Idea: let's call it smart brutal, easier than #45  *
 *  Remark: iterator...                                *
 * *************************************************** *
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return true;
        int x = 0;
        int y = x + nums[x];
        while( y < len - 1 ){
            int bound = y + 1;
            int newx = x;
            int newy = y;
            for(int i = x + 1; i < bound; i++){
                if( i + nums[i] > newy ){
                    cout << i;
                    newy = i + nums[i];
                    newx = i;
                }
            }
            if(newx == x) return false;
            x = newx;
            y = newy;
            
        }
        return true;
    }
};
