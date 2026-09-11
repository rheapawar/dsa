class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.length();
        for(int i = 0; i < n/2; i++){
            s[i] = s[n - i - 1] = min(s[i], s[n - i - 1]);
        }
        return s;
    }};