/* ********************************************* *
 *      Annie Wang 2016.11.30                    *
 *  Idea: simple                                 *
 *  Remark: N/A                                  *
 * ********************************************* *
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        map<char, char> m2;
        int n = s.size();
        if( n != t.size() ) return false;
        if( n == 0 ) return true;
        for( int i = 0; i < n; i++ ){
            if( m.find(s[i]) != m.end() ){
                if( m[s[i]] != t[i] ) return false;
            } else if( m2.find(t[i]) != m2.end() ){
                return false;
            } else {
                m[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
        }
        return true;
    }
};
