class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //general idea, kinda do a dfs on if a character starts with the first letter of word, and then do a recursive sense where u check in on the element can provid the x, y and then this restricts ur space for the search space, and then also the index of what character we are currently trying to locate
        bool found = false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]) found = helper(board, word, 0, i, j);
                if(found) return true;
            }
        }
        return found;
    }

    bool helper(vector<vector<char>> &board, const string &word, int idx, int x, int y){
        if (x < 0 || x > board.size()-1 || y < 0 || y > board[0].size()-1) return false;
        if (board[x][y] != word[idx]) return false; 
        if(idx == word.length() - 1) return true;
        char temp = board[x][y];
        board[x][y] = '#';
    
        bool found = helper(board, word, idx+1, x-1, y) || helper(board, word, idx+1, x+1, y) || helper(board, word, idx+1, x, y-1) || helper(board, word, idx+1, x, y+1);
    
        //combine all the returns form these starting points and then also check if there is an elements 
        //how to mark elements that were already used and cannot be used again??
        /*when doing backtracking then, need to somehow make sure sending node or anything adjacent would not work but how can we do thi? oh edit the squares that we already used to be some other character*/
        board[x][y] = temp;
        return found;
    }
};