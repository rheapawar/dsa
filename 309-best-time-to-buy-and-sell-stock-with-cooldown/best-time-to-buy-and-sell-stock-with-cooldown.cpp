class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*would want to keep track of buy previous day, then sell, keep track of curr min, and then a difference variable, plus the index of it would u wanna do a memo and have it be like where the previous element - would u wanna have one axis of memo be the day u are on and then the max profit u would make if u bought that day?*/

        if(prices.empty()) return 0;

        int hold = -prices[0];
        int cool = 0;
        int sold = 0;

        for(int i = 1; i < prices.size(); i++){
            int prev_h = hold;
            int prev_c = cool;
            int prev_s = sold;

            hold = max(prev_h, prev_c - prices[i]);
            sold = prev_h + prices[i];
            cool = max(prev_c, prev_s);
        }

        return max(cool, sold);
    }
};