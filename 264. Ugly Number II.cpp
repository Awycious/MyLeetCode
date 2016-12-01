/* ************************************************ *
 *          Annie Wang 2016.11.30                   *
 *  Idea: divide into 3 groups, make sure in order  *
 *  Remark: also remove duplicates                  *
 * ************************************************ *
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n < 1) return 0;
        if(n == 1) return 1;
        int opt;
        int temp;
        queue<int> l2, l3, l5;
        l2.push(2);
        l3.push(3);
        l5.push(5);
        
        while(--n){
            int a = l2.front();
            int b = l3.front();
            int c = l5.front();
            if(a < b){
                if(a < c){
                    l2.pop();
                    opt = a;
                } else{
                    if(a == c) l2.pop();
                    l5.pop();
                    opt = c;
                }
            } else {
                if(b < c){
                    if(a == b) l2.pop();
                    l3.pop();
                    opt = b;
                } else{
                    if(c == b) l3.pop();
                    if(a == c) l2.pop();
                    l5.pop();
                    opt = c;
                }
            }
            l2.push(2*opt);
            l3.push(3*opt);
            l5.push(5*opt);
        }
        return opt;
    }
};
