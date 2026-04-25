class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board[0].size(); i++){
            if(board[0][i] == 'O') helper(board, 0, i);
        }
        for(int i = 0; i < board.size(); i++){
            if(board[i][0] == 'O') helper(board, i, 0);
        }
        int b = board.size() -1;
        for(int i = 0; i < board[0].size(); i++){
            if(board[b][i] == 'O') helper(board, b, i);
        }
        int c = board[0].size() -1;
        for(int i = 0; i < board.size(); i++){
            if(board[i][c] == 'O') helper(board, i, c);
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'Z') board[i][j] = 'O';
            }
        }
        
    }

    void helper(vector<vector<char>> &board, int i, int j){
        board[i][j] = 'Z';
        if(i > 0 && board[i-1][j] == 'O') helper(board, i-1, j);
        if(i < board.size() -1 && board[i+1][j] == 'O') helper(board, i+1, j);
        if(j < board[0].size() -1 && board[i][j+1] == 'O') helper(board, i, j+1);
        if(j > 0 && board[i][j-1] == 'O') helper(board, i, j-1);

    }
    
};
