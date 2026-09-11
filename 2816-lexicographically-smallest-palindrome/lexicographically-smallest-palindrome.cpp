class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int right = s.length()-1;
        int left = 0;
        while(left < right){
            s[left] = s[right] = min(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }};