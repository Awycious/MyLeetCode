/* *************************************************************** *
 *      Annie Wang 2016.11.29                                      *
 *  Idea: set a number to the spot, then check if the sodoku is    *
 *      solvable, if not, go to next number                        *
 *  Remark: when a number is not valid, remember to set the spot   *
 *      back:)                                                     *
 * *************************************************************** *
 */


class Solution {
private:
    bool solve(int x, vector<vector<char>>& board){
        // we are processing the xth node
        if( x == 81 ) return true;
        
        int a = x / 9; // ath row
        int b = x % 9; // bth column
        
        if( board[a][b] != '.' ) return solve(x+1, board);
        
        int aa = a / 3 * 3; // the start point of the square 
        int bb = b / 3 * 3;
        
        for( int i = 1; i < 10; i++ ){
            bool isok = true;
            char c = i + '0';
            board[a][b] = c;
            // check if c is ok for xth node
            
            for( int j = 0; j < 9; j++ ){
                // no row or column duplicate
                if( board[a][j] == c && j != b ){
                    isok = false;
                    break;
                } else if ( board[j][b] == c && j != a ){
                    isok = false;
                    break;
                }
                // no 3 by 3 square duplicate
                int aaa = aa + (j / 3);
                int bbb = bb + (j % 3);
                if( board[aaa][bbb] == c && (aaa != a || bbb != b) ){
                    isok = false;
                    break;
                }
            }
            // if the value is ok to be here and no error from future, return true
            if( isok && solve( x+1, board ) ){
                return true;
            } else {
                board[a][b] = '.';
            }
        }
        // checked all 9 values, no available
        return false;
        
        
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(0, board);
    }
};
