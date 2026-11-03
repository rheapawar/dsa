class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*general idea, make sure to buy each time the next day is greater than the previous and sell if the next day will be lower and u have a stock*/
        int profit = 0;
        int purchase_price = -1;
        for(int i = 0; i < prices.size()-1; i++){
            if(purchase_price != -1 && purchase_price < prices[i]){
                profit += prices[i] - purchase_price;
                purchase_price = -1;
            }
            if(purchase_price == -1 && prices[i] < prices[i+1]){
                purchase_price = prices[i];
            }
        }
        if (purchase_price != -1) profit += prices[prices.size()-1] - purchase_price;
        return profit;
    }
};