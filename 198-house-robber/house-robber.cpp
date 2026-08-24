class Solution {
public:
    int rob(vector<int>& nums) {
        /*cant rob two adjacent houses and so need to determine the max amount of money of */
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        int p1 = 0;
        int p2 = 0;
        for(auto n : nums){
            int tmp = p1;
            p1 = max(n + p2, p1);
            p2 = tmp;
        }
        return max(p1, p2);
    }
};