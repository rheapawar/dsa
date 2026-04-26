class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int num = days[days.size() -1];
        vector<int> memo(num+1);
        vector<bool> x(366, false);
        for(int d : days) x[d] = true;        
        for(int i = 1; i <= num; ++i){
            if(!x[i]){
                memo[i] = memo[i-1];
                continue;
            }
            if(i < 7){
                memo[i] = min(min(memo[i-1] + costs[0], costs[1]), costs[2]);
           }
            else if(i < 30){
                memo[i] = min(min(memo[i-1]+costs[0], memo[i-7]+ costs[1]), costs[2]);
            }
            else{
                memo[i] = min(min(memo[i-1]+costs[0],memo[i-7]+costs[1]), memo[i-30] + costs[2]);
            }
        }
        return memo[num];
    }
};