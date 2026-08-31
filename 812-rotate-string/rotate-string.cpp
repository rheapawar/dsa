class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i = 0; i < s.length(); i++) {
            if(s == goal) return true;
            s += s[0];
            s = s.substr(1);
        }
        return false;
    }
};