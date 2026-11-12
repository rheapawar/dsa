class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*use prefix and postfix products and then multiply one into the other and return that result*/
        int n = nums.size();
        vector<int> prefix(n, 1);
        for(int i = 1; i < n; i++){
            prefix[i] = nums[i-1]*prefix[i-1];
        }
        int postfix = 1;
        for(int i = prefix.size()-1; i >= 0; i--){
            prefix[i] *= postfix;
            postfix *= nums[i];
        }
        return prefix;
    }
/*
    prefix = [1,1,2,6]
    postfix = [1,12,4,1]

    nums = [1,2,3,4]*/
};