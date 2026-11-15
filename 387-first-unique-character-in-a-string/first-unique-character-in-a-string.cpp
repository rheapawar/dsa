class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> seen;
        for(char c: s){
            seen[c]++;
        }
        for(int i = 0; i < s.length(); i++){
            if(seen[s[i]] == 1) return i;
        }
        return -1;
    }
};