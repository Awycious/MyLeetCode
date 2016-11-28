/* ************************************************************************ *
 *      Annie Wang 2016.11.24                                               *
 * Idea: O(n), go through the string and push stack when encounter a '(',   *
 *      pop when ')'                                                        *
 * Remark: string.erase() costs a lot of time, when with erase the running  *
 *      time was 946ms and 26ms when removed                                *
 * P.S.: soooo happy with this question, my code is actually 2 times faster *
 *      than the solution found online                                      *
 * ************************************************************************ *
 */
 
class Solution {
public:
    int calculate(string s) {
        // defination
        stack<int> opt; // stack of results
        stack<int> sign; // stack of '+' and '-', +1 for +, -1 for -
        int n = s.size(); // string length
        
        // initialization
        opt.push(0);
        sign.push(1);
        int i = 0;
        while( i < n ){
            
            char x = s[i];
            i++;
            
            // cout << "Before iteration, s = " << s << " and opt = " << opt.top() << ", x is keeping char " << x << endl;
            // number
            if( isdigit( x ) ){
                int a = x - '0';
                
                while( isdigit( x = s[i] ) ){
                    i++;
                    a *= 10;
                    a += x - '0';
                }
                
                a *= sign.top();
                a += opt.top();
                opt.pop();
                opt.push(a);
            }
            // sign +-
            else if( x == '+' || x == '-' ){
                sign.pop();
                if(x == '+') sign.push(1);
                else sign.push(-1);
            }
            // bracket open (
            else if( x == '(' ){
                opt.push(0);
                sign.push(1);
            }
            // bracket close )
            else if( x == ')' ){
                sign.pop();
                int a = sign.top() * opt.top();
               
                opt.pop();
                a += opt.top();
                opt.pop();
                opt.push(a);
            }
            // other
            else if( x != ' '){
                cout << "Error in the string s!!!! \n";
            } else {}
            // cout << "After iteration, s = " << s << " and opt = " << opt.top() << endl;
        }
        return opt.top();
        
        
    }
};


/* First trial:
 * Get correct solution but TLE
 * Idea: O(n) algorithm, move from the beginning of string to the end,
 *      use different method to deal with sign, number, and brackets,
 *      when encounter a bracket, use recursion to calculate 
 *      result from the open bracket to the close bracket, then calculate
 *      as a number
 * Remark: string.erase(a,n)
 * Improvement: next trial, use stack to replace recursion
 */
/*
class Solution {
private:
    string str;
    
    int calc2(){
        int n = str.size(); // string length
        int opt = 0; // the output value
        bool plus = true; // whether doing plus
        
        // Let's do the string
        while( str != "" ){
            char x = str[0];
            str.erase(0, 1);
            //cout << "Before iteration, str = " << str << " and opt = " << opt << ", x is keeping char " << x << endl;
            // encounter a number
            if( isdigit( x ) ){
                int a = x - '0';
                
                while( isdigit( x = str[0] ) ){
                    a *= 10;
                    a += x - '0';
                    str.erase(0, 1);
                    x = str[0];
                }
                
                if(plus) opt += a;
                else opt -= a;
            } 
            
            // when encounter a sign '+' or '-'
            else if( x == '+' || x == '-' ){
                plus = x == '+';
            }
            
            // when encounter a open bracket '('
            else if( x == '(' ){
                if(plus){
                    opt += calc2();
                } else {
                    opt -= calc2();
                }
            }
            // when encounter a close bracket ')'
            else if( x == ')' ){
                break;
            }
            // when encounter sth not a space
            else if( x != ' ' ) cout << "Error!\n";
            //cout << "After iteration, str = " << str << " and opt = " << opt << endl;
        }
        return opt;
    }

public:
    int calculate(string s) {
        str = s;
        return calc2();
    }
};
*/
