class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int intervals = 0;
        vector<int> counts(26, 0);
        int max_freq = 0;
        for(char c : tasks){
            max_freq = max(max_freq, ++counts[c - 'A']);
        }
        int num_max = 0;
        for(int c : counts){
            if(c == max_freq) num_max++;
        }
        intervals = (max_freq - 1)*(n+1) + num_max;
        return max(intervals, (int)tasks.size());
    }
};