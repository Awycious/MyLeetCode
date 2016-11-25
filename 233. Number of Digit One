/* *********************************************************************** * 
 *          Annie Wang 2016.11.25                                          *
 * Idea: f(9) = 1; f(19) = 1 + 10 = 11; f(199) = 1 * 20 + 10 * 2 + 100...  *   
 *      Same idea as convert the number into a string, but I don't like    *
 *      the string cuz it costs space.                                     *
 * Remark: be very careful with the iterators                              *
 * *********************************************************************** *
 */
class Solution {
public:
    int countDigitOne(int n) {
        
        if ( n < 0 ) return 0;
        int opt = 0;
        unsigned long d = 10;
        
        while( n / d > 0 ){
            // cout << d << endl;
            d *= 10;
        }
        
        d /= 10;
        while( d > 0 ){
            
            int a = n / d % 10; // the checking number 
            int b = n % d; // the rest
            int c = n / d / 10; // the part before a
            
            opt += c * d;
            opt += ( a > 1 ) ? d : (a * (b + 1));
            
            d /= 10;
        }
        return opt;
    }
};
