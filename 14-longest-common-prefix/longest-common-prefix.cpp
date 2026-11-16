class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(string s : strs){
            string match;
            int i = 0;
            while(i < s.length() && i < prefix.length() && s[i] == prefix[i]){
                match += prefix[i];
                i++;
            } 
            prefix = match;
        }
        return prefix;
    }
};