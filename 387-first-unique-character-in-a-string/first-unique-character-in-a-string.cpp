class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> seen(26);
        for(char c: s){
            seen[c - 'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(seen[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};