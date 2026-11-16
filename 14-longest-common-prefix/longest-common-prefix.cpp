class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(string s : strs){
            if(s.find(prefix) == 0) continue;
            while(s.find(prefix) != 0 && prefix != ""){
                prefix = prefix.substr(0, prefix.length()-1);
            }
        }
        return prefix;
    }
};