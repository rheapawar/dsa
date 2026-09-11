class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;

        while(left < right){
            if(s[left] != s[right]){
                (s[left] - 'a' < s[right] - 'a') ? s[right] = s[left] : s[left] = s[right];
            }
            left++;
            right--;
        }
        return s;
    }
};