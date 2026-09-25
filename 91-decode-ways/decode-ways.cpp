class Solution {
public:
    int numDecodings(string s) {
        /*idea is to shift between grouping numbers by 1 and by 2 if the prev is a 1 or 2, not 0 or not greater and second is less than 6 if first is a 
        
        */
        if(s[0] == '0') return 0;
        int dp = 0;
        int p1 = 1;
        int p2 = 1;
        int n = s.length();
        for(int i = n -1; i >= 0; i--){
            if(s[i] != '0') dp += p1;
            if(i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) dp += p2;
            p2 = p1;
            p1 = dp;
            dp = 0;
        }
        return p1;
    }
};