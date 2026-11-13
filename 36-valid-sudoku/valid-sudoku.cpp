class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*first traverse over the rows, then over the cols, if at any point, return -- use an unordered set to keep track of the elements we have seen so far, reset at each time*/

        unordered_set<int> seen;
        //rows first
        for(int i = 0; i < 9; i++){
            seen.clear();
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && !seen.insert(board[i][j]).second) return false;
            }
        }
        //checks the cols
        for(int i = 0; i < 9; i++){
            seen.clear();
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.' && !seen.insert(board[j][i]).second) return false;
            }
        }
        //i = box number
        for(int i = 0; i < 9; i++){
            seen.clear();
            for(int x = 0; x < 3; x++){
                for(int y = 0; y < 3; y++){
                    int x_idx = 3*(i/3) + x;
                    int y_idx = 3*(i % 3) + y;
                    if(board[x_idx][y_idx] != '.' && !seen.insert(board[x_idx][y_idx]).second) return false;
                }
            }
        }
        return true;
        //now check boxes
        //if the
        /*
        
        0,0 0,1 0,2
        1,0 1,1 1,2
        2,0 2,1 2,2

like iterate over the box number, if the box number is less than 3, then row, 3*box no + 
if box number mod 3 - cols shold be (j mod 3)
okay so for the col number it should be the (box no mod 3) + 1,2,3 and then for the rows box no /3 + 1,2,3

        0,3 0,4 0,5
        1,3 1,4 1,5
        
        */
    }
};