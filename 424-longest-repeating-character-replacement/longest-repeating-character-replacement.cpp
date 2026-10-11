class Solution {
public:
    int characterReplacement(string s, int k) {
        /*consider the most frequent letter in a window, and then how many non of those elements are in the current window and if this is <= k then perfect
        concerns--> how to know the most frequent letter in current window, and when u exceed the number
        
        */
        vector<int> counts(26, 0);
        int left = 0;
        int m = 0;
        int streak = 0;
        for(int i = 0; i < s.length(); i++){
            int x = s[i] - 'A';
            counts[x]++;
            m = max(m, counts[x]);

            if(i - left + 1 - m > k){
                int y = s[left] - 'A';
                counts[y]--;
                left++;
            }
            streak = max(streak, i - left + 1);
        }
        return streak;
    }
};