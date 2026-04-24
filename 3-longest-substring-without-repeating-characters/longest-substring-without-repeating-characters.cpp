class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int max = 0;
        int left = 0;
        for(int i = 0; i< s.length(); i++){

         if(m.find(s[i]) == m.end() || m[s[i]] < left){
            if(max < i - left + 1) max = i - left + 1;
            m[s[i]] = i;
         }
         else{
            if(m[s[i]] >= left) left = m[s[i]] + 1;
            m[s[i]] = i;

         }
        }
        
        return max;
    }

};