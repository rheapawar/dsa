class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*brute force, unordered map and return automatically if any element has greater than 0, can also sort it and check adjacent elements*/

        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};