class Solution {
public:
  
    vector<vector<int>> permute(vector<int>& nums) {
        /*want to swap the positioning of potential elements at each level, basically change the index of the element we are switchiting at
        okay so basically start w 123, swap the last two elements so that there is 1 3 2 and then consider whether
        
        how can we call a path compelte, at each iteration, you would like to push back into the vector */
        vector<vector<int>> perms;
        genPerms(nums, perms, 0);
        return perms;

    }

    void genPerms(vector<int> &nums, vector<vector<int>> &perms, int idx){
        if(idx == nums.size()){
            perms.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            swap(nums[i],nums[idx]);
            genPerms(nums, perms, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};