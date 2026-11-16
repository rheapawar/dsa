class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*maybe do two sum but instead have one element be fixed and we iterate thru*/
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;

                int left = i + 1;
                int right = n - 1;
                while(left < right){
                    int sum = nums[left] + nums[right] + nums[i]; 
                    if(sum == 0){
                        res.push_back({nums[left], nums[right], nums[i]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left - 1]) left++;
                        while(right > left && nums[right] == nums[right+1]) right--;
                    }
                    else if(sum < 0) left++;
                    else right--;
                    
                }
            

        }
        return res;
    }
};