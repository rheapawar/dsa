class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 1;
        int start = 0;
        string palindrome = s.substr(0,1);
        for(int i = 1; i < s.length(); i++){
            int odd = expand(s, i-1, i+1);
            int even = expand(s, i-1, i);
            if(odd > longest){
                longest = odd;
                start = i - odd/2;
            }
            if(even > longest){
                longest = even;
                start = i - even/2;
            }
            palindrome = s.substr(start, longest);
            
        }
        return palindrome;
    }

    int expand(const string &s, int left, int right){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
            }
        return right - left - 1;
    }
};