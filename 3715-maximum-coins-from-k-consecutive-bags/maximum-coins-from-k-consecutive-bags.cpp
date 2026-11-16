class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        /*essentially sliding window just with another calculation dimensions
        
        have a max, and while num_bags < k, just keep adding them up
        int bag_sum = coins[i][2]*(coins[i][1] - coins[i][0]);
        
        if num_bags = k, then delete the prev and add the next, oh wait its not like down a whole thing its within a vector itself

        instead keep adding up while num_bags < k, keep the index and bag number of the fist 
        */
    long long total = 0;
    long long largest = 0;
    int j = 0;
    int n = coins.size();
    sort(coins.begin(), coins.end());
    for(int i = 0; i < n; i++){
        long long right = coins[i][0] + k - 1;
        while(j < n && coins[j][1] <= right){
            total += 1LL*coins[j][2]*(coins[j][1] - coins[j][0] + 1);
            j++;
        }
        
        long long partial = 0;
        if(j < n && coins[j][0] <= right){
            partial += 1LL*coins[j][2]*(right - coins[j][0] + 1);
        }
        largest = max(largest, total + partial);
        
        if(j > i){
            total -= 1LL * coins[i][2] * (coins[i][1] - coins[i][0] + 1);
        }
        else{
            j = i + 1;
        }
    }
    total = 0;
    int i = 0;
    for(int j = 0; j < n; j++){
        long long left = 1LL*(coins[j][1] - k + 1);

        total += 1LL*(coins[j][2])*(coins[j][1]- coins[j][0] + 1);
        while(i <= j && coins[i][1] < left){
            total -= 1LL*(coins[i][2])*(coins[i][1] - coins[i][0] + 1);
            i++;
        }

        long long overshoot = 0;
        if(i <= j && coins[i][0] < left){
            overshoot = 1LL*coins[i][2]*(left - coins[i][0]);
        }
        largest = max(largest, total - overshoot);

    }
    return largest;
    } 
};