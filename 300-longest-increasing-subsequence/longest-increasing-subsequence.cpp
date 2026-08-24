class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*index of the prev min and th
        
        10,9,2,3,5,7,4,5
        issue is if you run into a number where the streak before doesnt include the actual pre value then u cant increment by one - so does dp instead hold the value of the largest streak containing that element and then a separate variable for max streak so far?
        */
        vector<int> memo(nums.size(), 1);
        int streak = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && memo[i] < memo[j] + 1){
                    memo[i] = memo[j] + 1;
                }
            }
        }
        return *max_element(memo.begin(), memo.end());
    }
};