class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256, -1);
        int left = 0;
        int longest = 0;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(map[c] != -1 && map[c] >= left){
                left = map[c] + 1;
            }
            map[c] = i;
            longest = max(longest, i - left + 1);
        }
        return longest;
    }
};