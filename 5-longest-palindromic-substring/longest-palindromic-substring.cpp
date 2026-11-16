class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 1;
        string palindrome = s.substr(0,1);
        for(int i = 1; i < s.length(); i++){
            string odd = expand(s, i-1, i+1);
            string even = expand(s, i-1, i);
            if(odd.length() > longest && odd.length() > even.length()){
                longest = odd.length();
                palindrome = odd;
            }
            else if(even.length() > longest && even.length() > odd.length()){
                longest = even.length();
                palindrome = even;
            }
            
        }
        return palindrome;
    }

    string expand(string s, int left, int right){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
            }
        return s.substr(left + 1, right - left - 1);
    }
};