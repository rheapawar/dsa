class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid = (right - left)/2 + left;
        while(left < right){
            mid = (right - left)/2 + left;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid;
        }
        return left;
    }
};