class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //validating each row
        vector<bool> count(10);
        for(int i = 0; i < board.size(); i++){
            count.assign(10, false);
            for(int j = 0; j < board[i].size(); j++){
                char c = board[i][j];
                if(c != '.'){
                    if (count[c - '0']) return false;
                    count[c - '0'] = true;
                }
            }
        }
        //validating columns
        for(int i = 0; i < 9; i++){
            count.assign(10, false);
            for(int j = 0; j < 9; j++){
                char c = board[j][i];
                if(c != '.'){
                    if (count[c - '0']) return false;
                    count[c - '0'] = true;
                }
            }
        }
        //validating subboxes
        for(int i = 0; i < 9; i++){
            count.assign(10, false);
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    char c = board[3*(i/3) + j][3*(i%3) + k];
                    if(c != '.'){
                        if (count[c - '0']) return false;
                        count[c - '0'] = true;
                    }
                } 
            }
        }
        return true;
    }
};