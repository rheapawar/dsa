class Solution {
public:
    int minTimeToType(string word) {
        int sec = 1 + min(abs(word[0] - 'a'), abs(26 - (word[0] - 'a')));
        for(int i = 1; i < word.size(); i++){
            int steps = min(abs(word[i] - word[i-1]), 26 - abs(word[i] - word[i-1]));
            sec += steps + 1;
        }
        return sec;
    }
};