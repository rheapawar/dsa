class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*go across a row, then down the column, then reverse across the bottom most row and then up the col and then right until bounds infringe on each other
        
        essentially use while loop, i for rows, j for cols
        for i = 0, go from 0 to n
        then once u reach bound, go down the outer from i to m, move m to subtract m and increase i

        then go from k to 0 and after that, increase to j to 1 and decrease k

        to determine direction, if i and j mod 2 is positive, then go in forward direction, else go in reverse
        
        */
        vector<int> res;
        int bottom = matrix.size();
        int right = matrix[0].size();
        res.reserve(bottom*right);
        int upper = 0; 
        int left = 0;
        int bound = 0;
        while(left < right && upper < bottom){
            for(int i = left; i < right; i++){
                res.push_back(matrix[upper][i]);
            }
            upper++;
            for(int j  = upper; j < bottom; j++){
                res.push_back(matrix[j][right-1]);
            }
            right--;

            if (upper < bottom) {
                for (int i = right - 1; i >= left; i--) {
                    res.push_back(matrix[bottom - 1][i]);
                }
                bottom--;
            }

            if (left < right) {
                for (int j = bottom - 1; j >= upper; j--) {
                    res.push_back(matrix[j][left]);
                }
                left++;
            }

        }
        return res;
    }
};