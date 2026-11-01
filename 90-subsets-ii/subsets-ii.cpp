class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*consider the elements to be sorted first, and then do we check for whether the current element we are accessing is the same as a previous element??do we create an unordered set of vectors?? or do the same thing where when u are on a certain level, cannot choose the same element, every intermediate action is another subset, so count that and then continue - may never reach end of vector*/

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.reserve(pow(2,nums.size()));
        vector<int> curr;
        curr.reserve(nums.size());
        subset(nums, res, curr, 0);
        return res;

    }

    void subset(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int i){
        res.push_back(curr);
    
        for(int j = i; j < nums.size(); j++){
            if(j > i && nums[j] == nums[j-1]) continue;
            curr.push_back(nums[j]);
            subset(nums, res, curr, j+1);
            curr.pop_back();
        }
    }
};