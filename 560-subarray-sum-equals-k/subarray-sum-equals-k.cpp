class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*what im leaning towards, start at beginning of array and then while curr sum is less than k, continue adding elements, if u reach point where too large, then subtract leftmost element and keep doing while its greater, then check again and keep progressing right
        
        consider negative numbers, if nums[left] is negative then if its less than, consider removing it*/

        
        int currSum = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        int num = 0;
        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            num += map[currSum-k];
            map[currSum]++;
        }
        return num;
    }
};