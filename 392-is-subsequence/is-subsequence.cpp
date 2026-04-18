class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        int x = 0;
        int y = 0;
        while(x<s.size() && y < t.size()){
            if(s[x] == t[y]){
                x++;
                y++;
            }
            else{
                y++;
            }
        }
        if(x < s.size()) return false;
        return true;
        
        }
    
};