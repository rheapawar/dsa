class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*binary search similar to min in rotated sorted array and first compare mid to the element that is being searched for if the element is too large then check the left and right bounds, if mid is end 
        
        first check which half is sorted rather than checking where the value is initially */

        int left = 0; 
        int right = nums.size() - 1;
        int mid;

        while(left <= right){
            mid = left + (right - left)/2;
            if(nums[mid] == target) return mid;
            if(nums[left] <= nums[mid]){
                if(nums[mid] > target && nums[left] <= target) right = mid - 1;
                else left = mid + 1;
            }
            else{
                if(nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;        
    }
};