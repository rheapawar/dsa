class Solution {
public:
    int countVowelStrings(int n) {
        string arr[5] = {"a", "e", "i", "o", "u"};
        vector<vector<int>> memo(n + 1, vector<int>(5,0));
        int sum = 0;
        for(size_t i = 1; i <= n; i++){
            memo[i][0] = 1;
            sum = 1;
            for(int j = 1; j < 5; j++){
                memo[i][j] = memo[i-1][j] + memo[i][j-1];
                sum += memo[i][j];
            }
        }
        return sum;
    }
};