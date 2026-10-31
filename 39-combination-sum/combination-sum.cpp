class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        /*when u get to the element, consider using*/
        vector<vector<int>> res;
        vector<int> candidate;
        combine(res, candidates, candidate, 0, target, 0);
        return res;
    }

    void combine(vector<vector<int>> &res, vector<int> &candidates, vector<int> &curr, int i, int target, int sum){
        if(sum == target){
            res.push_back(curr);
            return;
        } 
        if(sum > target || i == candidates.size()){
            return;
        }
        sum += candidates[i];
        curr.push_back(candidates[i]);
        combine(res, candidates, curr, i, target, sum);
        sum -= candidates[i];
        curr.pop_back();
        combine(res,candidates, curr, i+1, target, sum);
    }
};