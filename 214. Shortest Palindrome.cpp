/*class Solution {
private: 
    bool ispal(string s){ // check if a string is palindrome
        int mid = s.size() / 2 + 1;
        int n = s.size();
        for(int i = 0; i < mid; i++){
            if(s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string s2;
        // s2 is reverse of s
        // find the longest subtring s' s.t.  s2 = as', s = s'b, where a and b
        // are 2 substrings of s2 and s respectively
        // => s' is palindrome, reduce the problem to find the longest palindrome
        // substring at the beginning of s 
        int sp_len = 1;
        for(int i = n; i > 0; i--){
            if(ispal(s.substr(0, n))){
                sp_len = i;
                break;
            }
        }
        for(int i = n - 1, j = 0; i > sp_len; i--, j++){
            s2[j] = s[i];
        }
        s = s2 + s;
        return s;
    }
};*/

/* **** above is the first trial, failed on an extremely long test *********** */
/* Let's use KMP! */
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int match[n];
        int k = 0;
        int j = 0;
        for(int i = n - 1; i >= 0; i--){
            
        }
        for(int i = n - 1, j = 0; i > sp_len; i--, j++){
            s2[j] = s[i];
        }
        s = s2 + s;
        return s;
    }
};
