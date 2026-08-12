class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /* 
        need to swap rows and columns essentially, first row and last column so n x n matrix
        0th row and n-1 column swap and then reverse the col

        or for four way swap cycle
        to do this, iterate over the rows so matrix.size(), for each, need to swap 
        but need to prevent overwriting data, so is it simply that every data point has to move 
        new row = old col
        new col = n - 1 - old row
        how to know when you have finished, maybe total count of the number of tiles changed??
        do like a dfs

        */

        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        /*

        alt answer
        
        int n = matrix.size();
        for(int i = 0; i < n/2; i++){
            for(int j = i; j < n - i - 1; j++){
                int top_left = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = top_left;
            }
        }
        */
    }
};