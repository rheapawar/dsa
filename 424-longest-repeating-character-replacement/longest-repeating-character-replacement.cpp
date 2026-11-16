class Solution {
public:
    int characterReplacement(string s, int k) {
        /*need to maintain what is the max frequency element in the window
        keep a map of the frequency counts that way as we go thru the string, know who is the most frequent, and then keep a left pointer so we know how many non most frequent element there are
        if it becomes greater than k, then need to go through and decrease the frequencies of eveyrthing we are removing
        
        */
        int left = 0;
        int max_freq = 0;
        int longest = 0;
        unordered_map<char, int> freqs;
        for(int i = 0; i < s.length(); i++){
            freqs[s[i]]++;
            max_freq = max(max_freq,freqs[s[i]]);
            while(i - left + 1 - max_freq > k){
                freqs[s[left]]--;
                left++;
            }
            longest = max(longest, i - left + 1);
        }
        return longest;
    }
};