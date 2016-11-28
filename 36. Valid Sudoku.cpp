/* ************************************************************* *
 *      Annie Wang 2016.11.26                                    *
 * Idea: check if there are duplicates in each row, cols and 3x3 *
 * Remark: for short code, combine row check and col checm intp  *
 *          one part of code, when referencing a vector, use &   *
 * ************************************************************* *
 */
 
class Solution {
private:
    bool check_dup(char x, vector<bool>& check ){
        if(x == '.') return false;
        int a = x - '0';
        if(check[a]) return true;
        check[a] = true;
        return false;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // check rows and cols
        for(int i = 0; i < 9; i++){
            vector<bool> rcheck (9, false);
            vector<bool> ccheck (9, false);
            for(int j = 0; j < 9; j++){
                if( check_dup(board[i][j], rcheck) ) return false;
                if( check_dup(board[j][i], ccheck) ) return false;
            }
        }
        
        // check 3x3's
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                vector<bool> check (9, false);
                for(int ii = 0; ii < 3; ii++){
                    for(int jj = 0; jj < 3; jj++){
                        char x = board[i + ii][j + jj];
                        if( check_dup(x, check) ) return false;
                    }
                }
            }
        }
        return true;
    }
};
