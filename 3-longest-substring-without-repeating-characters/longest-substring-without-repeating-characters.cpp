class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*rough idea, keep a vector of the character counts currently in the window, then as ur traversing thru loop check if element is already in it, if not then add it in and increment streak, if  it is, then increment left pointer to next non repeating element, max ucrr and streak and then reset streak*/

        int best = 0;
        int streak = 0;
        unordered_map<char, int> map;
        int left = 0;
        for(int i = 0; i < s.length(); i++){
            char a = s[i];
            if(map.contains(a) && map[a] >= left){
                left = map[a] + 1;
                map[a] = i;
            }
            else{
                map[a] = i;
            }
            streak = i - left + 1;
            best = max(best, streak);
        }
        return best;
    }
};