/* ************************************************** *
 *      Annie Wang 2016.11.30                         *
 *  Idea: simple                                      *
 *  Remark: N/A                                       *
 * ************************************************** *
 */
class Solution {
public:
    bool isHappy(int n) {
        bool happy = true;
        map<int, int> m;
        while( n != 1 ){
            int x = 0;
            while( n > 0 ){
                x += pow(n%10, 2);
                n /= 10;
            }
            n = x;
            if( m.find(n) != m.end() ) return false;
            m[n] = 1;
        }
        return true;
    }
};
