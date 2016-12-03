/* ********************************************************* *
 *      Annie Wang 2016.12.02                                *
 * Idea: use stack to handle multiple bracket                *
 * Remark: isdigit(char) to determine if a char is digit     *
 * ********************************************************* *
 */
class Solution {
public:
    string decodeString(string s) {
        if(s == "") return s;
        stack<string> strs; // the reapeated string
        stack<int> rep; // the repeated times
        int n = s.size(); // length of s
        bool num = false;
        strs.push("");
        rep.push(1);
        // initialization
        
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                if(num){
                    int x = rep.top() * 10 + (s[i] - '0');
                    rep.pop();
                    rep.push(x);
                } else {
                    num = true;
                    rep.push(s[i] - '0');
                }
            } else if(s[i] == '['){
                if(num){
                    strs.push("");
                    num = false;
                } else {
                    cout << "Error, [ must follow a number\n";
                }
            } else if(s[i] == ']'){
                int x = rep.top();
                string y = strs.top();
                rep.pop();
                strs.pop();
                string addup = "";
                for(int j = 0; j < x; j++){
                    addup += y;
                }
                addup = strs.top() + addup;
                strs.pop();
                strs.push(addup);
            } else {
                string y = strs.top();
                strs.pop();
                y += string(1, s[i]);
                strs.push(y);
            }
        }
        return strs.top();
        
    }
};
