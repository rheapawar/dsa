class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        /*initial thought it dfs, iterate over entire board and consider adjacent cells when first letter is discovered*/
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0] && helper(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, string word, int idx, int i, int j){
        if(idx == word.length()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) return false;
        
        char temp = board[i][j];
        board[i][j] = '#';

        bool res = helper(board, word, idx+1, i-1, j) || helper(board, word, idx + 1, i+1, j) || helper(board, word, idx + 1, i, j-1) || helper(board, word, idx + 1, i, j+1);

        board[i][j] = temp;

        return res;
    }
};