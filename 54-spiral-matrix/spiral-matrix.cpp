class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
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