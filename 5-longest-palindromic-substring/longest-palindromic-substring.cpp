class Solution {
public:
    string longestPalindrome(string s) {
        /*idea is that u have to determine where the matching letters are,
        when u add another letter check from the last instance of that letter, when u add a letter to the existing palindrome, check if the window size expanded 1 to the left matches the newest letter    
        
        ex) 
        hicabacdf
        */
        if(s.length() == 1) return s;
        string res = "";
        for(int i = 0; i < s.length()-1; i++){
            string odd = expand(i,i,s);
            if(odd.length() > res.length()) res = odd;

            string even = expand(i,i+1,s);
            if(even.length() > res.length()) res = even;
        }
        return res;
    }

    string expand(int i, int j, string s){
        int left = i;
        int right = j;
        while(left >= 0 && right <= s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right - left - 1);
    }
};