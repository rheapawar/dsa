class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        /*initial thought it dfs, iterate over entire board and consider adjacent cells when first letter is discovered*/
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && helper(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, string word, int idx, int i, int j){
        int m = board.size();
        int n = board[0].size();

        if(idx == word.length()) return true;
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx]) return false;
        
        char temp = board[i][j];
        board[i][j] = '#';

        bool res = helper(board, word, idx+1, i-1, j) || helper(board, word, idx + 1, i+1, j) || helper(board, word, idx + 1, i, j-1) || helper(board, word, idx + 1, i, j+1);

        board[i][j] = temp;

        return res;
    }
};