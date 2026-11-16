class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        /*need to record the longest streak where the number of zeroes is less than or equal to k, when it breaks then will need to reset window to be where the second zero in the window is ( or basically just set it to be 1 more than the first zero in the window*/

        int first_zero = -1;
        int longest = 0;
        int num_zeroes = 0;
        int left = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                if(first_zero == -1) first_zero = i;
                num_zeroes++;
                while(num_zeroes > k){
                    if(nums[left] == 0) num_zeroes--;
                    left++;
                }
            }
            longest = max(longest, i - left + 1);
        }
        return longest;
    }
};