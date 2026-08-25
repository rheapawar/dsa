class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*initial thoughts:
        dp -> would it 
        create 2d dp, where you have the longest palindrome between any two indices 
        */
        int n = s.length();
        vector<int> memo(n);
        vector<int> prev(n);
        for(int i = n - 1; i>=0; i--){
            memo[i] = 1;
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]) memo[j] = 2 + prev[j-1];
                else memo[j] = max(prev[j], memo[j-1]);
            }
            prev = memo;
        }
        return memo[n-1];
    }
};