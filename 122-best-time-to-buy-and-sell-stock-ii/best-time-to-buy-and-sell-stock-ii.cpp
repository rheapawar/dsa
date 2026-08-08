class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int high = -1;
        int low = -1;
        int profit = 0;
        for(int i = 0; i < prices.size()-1; i++){
            if(prices[i] < prices[i+1]){
                high = prices[i+1];
                if(low == -1) low = prices[i];
            }
            else if(low != -1 && low < high){
                profit += high - low;
                low = -1;
                high = -1;
            }
            else{
                low = -1;
                high = -1;
            }
        }
        if(low != -1 && high != -1) profit += high-low;
        return profit;
    }
};