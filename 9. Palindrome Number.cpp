class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int y = x;
        int c = 0;
        while(y != 0){
            c = c * 10 + y % 10;
            y /= 10;
            cout << y << endl;
        }
        return x == c;
    }
};

/* ******************************** *
 *      Annie Wang 2016.11.20       *
 * Idea: reverse the number and     *
 *      compare                     *
 * Remark: negative numbers are not *
 *      palindrome                  *
 * ******************************** *
