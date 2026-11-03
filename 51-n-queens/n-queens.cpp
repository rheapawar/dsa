class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr(n);
        for(int i = 0; i < n; i++){
            curr[i] = string(n, '.');
        }
        placeQueen(res, curr, 0, n);
        return res;

        /*each length of the */

    }

    void placeQueen(vector<vector<string>> &res, vector<string> &board, int i, int n){
        if(i == n){
            res.push_back(board);
            return;
        }
        for(int j = 0; j < n; j++){
            if(isSafe(i, j, board)){
                board[i][j] = 'Q';
                placeQueen(res, board, i+1, n);
                board[i][j] = '.';
            }
        }
    }


   bool isSafe(int r, int c, vector<string>& board) {
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'Q') return false;
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
};