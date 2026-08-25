class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        /*just need to always choose the color ball w largest inventory, could do a max_heap pq but overflow*/
        const long long MOD = 1e9 + 7;
        sort(inventory.begin(), inventory.end(), greater<int>());
        inventory.push_back(0);
        long long profit = 0;
        long long width = 1;
        for(int i = 0; i < inventory.size() - 1 && orders > 0; i++){
            long long curr = inventory[i];
            long long next = inventory[i+1];
            long long count = width * (curr - next);
            
            if(orders >= count){
                profit += (width*(((curr+1)*curr/2) - (next*(next+1))/2)) % MOD;
                orders -= count;
                width++;
                /*
                15 - 3 = 12
                orders  = 1
                width = 2;
                how many levels back need to be decremented
                5,7,8,12 orders = 15

                12, 8, 7, 5
                need to determine what the base value is going to be - like how many are going to be left over
                so maybe create a sum of the whole thing, subtract and 


                */
            }
            else{
                long long x = orders/width;
                long long y = orders%width;
                long long tmp = curr - x;
                profit += (width*((curr*(curr+1)/2) - (tmp*(tmp + 1)/2))) % MOD;
                profit += (tmp*y) % MOD;
                break;
                /* need to split them across all the remaining
                8
                8,8,8,4
                */

            }
        }
        return profit % MOD;
        
        
    }
};