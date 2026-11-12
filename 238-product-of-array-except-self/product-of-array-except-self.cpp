class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*use prefix and postfix products and then multiply one into the other and return that result*/
        int n = nums.size();
        vector<int> postfix(n, 1);
        vector<int> prefix(n, 1);
        int j = n - 2;
        for(int i = 1; i < n && j >= 0; i++){
            prefix[i] = nums[i-1]*prefix[i-1];
            postfix[j] = nums[j+1]*postfix[j+1];
            j--;
        }
        for(int i = 0; i < prefix.size(); i++){
            prefix[i] *= postfix[i];
        }
        return prefix;
    }
/*
    prefix = [1,1,2,6]
    postfix = [1,12,4,1]

    nums = [1,2,3,4]*/
};