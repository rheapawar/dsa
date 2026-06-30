class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int left = 0; 
        int length = 0;
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); i++){
            char a = s[i];
            if(m.contains(a) && m[a] >= left){
                left = m[a] + 1;
                m[a] = i;
            }
            else{
                m[a] = i;
                length = max(i - left + 1, length);
            }
        }
        return length;
    }

};