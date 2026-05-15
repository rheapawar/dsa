class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //validating each row
        for(int i = 0; i < board.size(); i++){
            vector<int> count(10);
            iota(count.begin(), count.end(), 0);
            for(int j = 0; j < board[i].size(); j++){
                char c = board[i][j];
                if(c != '.'){
                    if (count[c - '0'] != c - '0') return false;
                    count[c - '0'] = -1;
                }
            }
        }
        //validating columns
        for(int i = 0; i < 9; i++){
            vector<int> count(10);
            iota(count.begin(), count.end(), 0);
            for(int j = 0; j < 9; j++){
                char c = board[j][i];
                if(c != '.'){
                    if (count[c - '0'] != c - '0') return false;
                    count[c - '0'] = -1;
                }
            }
        }
        //validating subboxes
        for(int i = 0; i < 9; i++){
            vector<int> count(10);
            iota(count.begin(), count.end(), 0);
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    char c = board[3*(i/3) + j][3*(i%3) + k];
                    if(c != '.'){
                        if (count[c - '0'] != c - '0') return false;
                        count[c - '0'] = -1;
                    }
                } 
            }
        }
        return true;
    }
};