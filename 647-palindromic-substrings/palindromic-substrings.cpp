class Solution {
public:
    int countSubstrings(string s) {
        /*main idea:

        abccbd
        abcacbd
        
        when u traverse thru the string, included all single chars as a valid palindrome

        then when u go to the next char, if there is a substring it is adjacent to, then does adding this and expanding the window one to the left if the bound is not already at 0 still result in a substring,
        does curr char and prev char form substring,, if yes expand the window around each element 

        will be 0(n^2) complexity
        
        */
        vector<int> dp(s.length(), 0);
        dp[0] = 1;
        for(int i = 1; i < s.length(); i++){
            dp[i] = expand(i-1,i,s) + expand(i,i,s);
            dp[i] += dp[i-1];
        }
        return dp[s.length()-1];
    }

    int expand(int i, int j, string s){
        int left = i;
        int right = j;
        int sum = 0;
        while(left >=0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
            sum++;
        }
        return sum;
    }
};