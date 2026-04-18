class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int diff = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] - min > diff) diff = prices[i] - min;
            if(prices[i] < min ) min = prices[i];
        }

        if(diff <= 0) return 0;
        else return diff;
    }
};