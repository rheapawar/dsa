class Solution {
public:
    int findMin(vector<int>& nums) {
        /*binary search to determine where the transition from min to max value is
        
        keep a left, right, and mid
        if mid > right, then left = mid + 1
        if mid < right
        */

        int left = 0; 
        int right = nums.size() - 1;
        int mid;

        while(left < right){
            mid = left + (right - left)/2;
            if(nums[mid] > nums[right]) left = mid + 1; 
            else right = mid;
        }
        return nums[left];
    }
};