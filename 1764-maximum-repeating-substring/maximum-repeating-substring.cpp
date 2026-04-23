class Solution {
public:
    int maxRepeating(string sequence, string word) {
        vector<int> memo(sequence.length() + 1, 0);
        size_t i = word.length();
        size_t j = word.length();
        int streak = 0;
        while(i <= sequence.length()){
            if(sequence.substr(i - j, j) == word){
                memo [i] = 1 + memo[i - j];
                streak = max(streak, memo[i]);
            }
            i++;
        }
        return streak;
    }
};