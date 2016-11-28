/* ************************************************************ *
 *      Annie Wang 2016.11.28                                   *
 *  Idea: simple arithmetic rule applied, started from the end  *
 *  Remark: multiple conditions                                 *
 * ************************************************************ *
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int add1 = 0;
        string opt = "";
        while( n1 >= 0 && n2 >= 0 ){
            int x = add1 + num1[n1] - '0' + num2[n2] - '0';
            add1 = x / 10;
            x = x % 10;
            opt = string( 1, x + '0' ) + opt;
            n1--;
            n2--;
        }
        while( n1 >= 0 ){
            int x = num1[n1] - '0' + add1;
            add1 = x / 10;
            x = x % 10;
            opt = string( 1, x + '0' ) + opt;
            n1--;
        }
        while( n2 >= 0 ){
            int x = num2[n2] - '0' + add1;
            add1 = x / 10;
            x = x % 10;
            opt = string( 1, x + '0' ) + opt;
            n2--;
        }
        if( add1 ) opt = "1" + opt;
        if(opt == "") return "0";
        return opt;
    }
};
