class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*main idea, incrementally start? should smaller be pushed first or second?, need to simply iterate thru all combinations so for 
        subsets two potential things, either add it or dont add it, so for each element should we spin off two recursive calls, one including the element and the other does not*/
        vector<vector<int>> res;
        vector<int> curr;
        genPerms(res, nums, curr, 0);
        return res;

    }

    void genPerms(vector<vector<int>> &res, vector<int> &nums, vector<int> &curr, int i){
        if(i >= nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        genPerms(res, nums, curr, i+1);
        curr.pop_back();
        genPerms(res, nums, curr, i+1);
    }
};