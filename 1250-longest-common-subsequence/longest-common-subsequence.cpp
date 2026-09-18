class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.length() + 1;
        int t2 = text2.length() + 1;

        vector<vector<int>> memo((t1), vector<int>(t2, 0));
        for(int i = 1; i < t1; i++){
            for(int j = 1; j < t2; j++){
                if(text1[i-1] == text2[j-1]) memo[i][j] = memo[i-1][j-1] + 1;
                else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
        return memo[t1-1][t2-1];


    }
};