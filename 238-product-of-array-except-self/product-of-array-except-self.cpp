class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int suffix = 1*nums[nums.size()-1];
        nums[nums.size()-1] = ans[nums.size()-1];
        for(int i = nums.size() - 2; i >=0; i--){
            int next = suffix * nums[i];
            nums[i] = suffix * ans[i];
            suffix = next;
        }
        return nums;
    }
};