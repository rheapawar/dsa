class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left = 0;
        int longest = 0;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(map.contains(c) && map[c] >= left){
                left = map[c] + 1;
            }
            map[c] = i;
            longest = max(longest, i - left + 1);
        }
        return longest;
    }
};