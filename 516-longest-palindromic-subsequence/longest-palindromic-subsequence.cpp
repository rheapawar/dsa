class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*initial thoughts:
        dp -> would it 
        create 2d dp, where you have the longest palindrome between any two indices 
        */
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n));
        for(int i = n - 1; i>=0; i--){
            memo[i][i] = 1;
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]) memo[i][j] = 2 + memo[i+1][j-1];
                else memo[i][j] = max(memo[i+1][j], memo[i][j-1]);
            }
        }
        return memo[0][n-1];
    }
};