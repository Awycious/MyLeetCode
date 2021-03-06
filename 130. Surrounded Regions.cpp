class Solution {
public:
    
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int n = board.size();
        int m = board[0].size();
        //vector<vector<bool>> iskeep (n, vector<bool> (m)); // vector<vector<bool>> iskeep (n, vector<bool> (m, false));
        
        // iterate for first and last row
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O') mySearch(0, j, board);
            if(board[n - 1][j] == 'O') mySearch(n - 1, j, board);
        }
        
        // iterate for the other rows
        for(int i = 1; i < n - 1; i++){
            for(int j = 0; j < m; j += m-1){
                if(board[i][j] == 'O') mySearch(i, j, board);
            }
            
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = (board[i][j] == '1') ? 'O' : 'X';
            }
        }
    }
private:

    void mySearch(int a, int b, vector<vector<char>>& board){
        if(board[a][b] == 'O'){
            board[a][b] = '1';
            int n = board.size();
            int m = board[0].size();
            
            if(a > 1) mySearch(a - 1, b, board);
            if(a < n - 1) mySearch(a + 1, b, board);
            if(b > 1) mySearch(a, b - 1, board);
            if(b < m - 1) mySearch(a, b + 1, board);
            
        }
    }
}; 


/* *************************************************************************************************************************
 * ****** Annie Wang 2016.11.17 ********************************************************************************************
 * *************************************************************************************************************************
 * URL: https://leetcode.com/problems/surrounded-regions/ ******************************************************************
 * Idea: search aroud the graph and bfs every 'O' found and marke them, then go through the graph change all other nodes ***
 * ***** to 'X'*************************************************************************************************************
 * Remark: when first started, was using a bool matrix to record the bfs result, since we are changing the graph, it is ****
 * ******* more convenient to mark on the graph rather than waste memory. In the previous method, running time error occurs*
 * ******* in some specific cases. *****************************************************************************************
 * *************************************************************************************************************************
