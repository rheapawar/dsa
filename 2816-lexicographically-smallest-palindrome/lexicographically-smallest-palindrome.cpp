class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.length();
        for(int i = 0; i < n/2; i++){
            (s[i] - 'a' < s[n - i - 1] - 'a') ? s[n - i - 1] = s[i] : s[i] = s[n - i - 1];
        }
        return s;
    }
};