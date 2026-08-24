class Solution {
public:
    int rob(vector<int>& nums) {
        /*cant rob two adjacent houses and so need to determine the max amount of money of */
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return max(dp[n-2], dp[n-1]);
    }
};