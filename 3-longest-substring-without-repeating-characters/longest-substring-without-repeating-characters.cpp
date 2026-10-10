class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*rough idea, keep a vector of the character counts currently in the window, then as ur traversing thru loop check if element is already in it, if not then add it in and increment streak, if  it is, then increment left pointer to next non repeating element, max ucrr and streak and then reset streak*/

        int best = 0;
        int streak = 0;
        unordered_map<char, int> map;
        int left = 0;
        for(int i = 0; i < s.length(); i++){
            if(map[s[i]] != 0){
                while(left <= i && s[left]!=s[i]){
                    map[s[left]] = 0;
                    left++;
                }
                left++;
                best = max(best, streak);
                streak = i - left + 1;
            }
            else{
                map[s[i]] = 1;
                streak++;
            }
        }
        return max(streak, best);
    }
};