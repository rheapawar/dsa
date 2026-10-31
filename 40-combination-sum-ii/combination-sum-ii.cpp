class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /*when need to avoid duplicates, always sort first and then also */
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        combine(res, curr, candidates, 0, target);
        return res;
    }

    void combine(vector<vector<int>> &res, vector<int> &curr, vector<int> &candidates, int i, int target){
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        if(target < 0 || i >= candidates.size()) return;
        for(int j = i; j < candidates.size(); j++){
            if(candidates[j] > target) break;
            if(j > i && candidates[j] == candidates[j-1]) continue;
            curr.push_back(candidates[j]);
            combine(res, curr, candidates, j+1, target - candidates[j]);
            curr.pop_back();
        }
       

    }
};